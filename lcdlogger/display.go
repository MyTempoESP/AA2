package lcdlogger

import (
	"context"
	"log"
	"strconv"
	"strings"
	"time"

	c "aa2/constant"

	"github.com/MyTempoesp/flick"
)

type SerialDisplay struct {
	Forth *flick.MyTempo_Forth

	Screen int
	action Action
}

func NewSerialDisplay() (display SerialDisplay, err error) {

	f, err := flick.NewForth("/dev/ttyACM1")

	if err != nil {

		log.Printf("Erro ao iniciar a comunicação com o arduino: %v\n", err)

		return
	}

	f.Start()

	f.Query("1 .")

	display.Forth = &f

	display.action = -1

	return
}

func (display *SerialDisplay) WaitKeyPress(d time.Duration) (hasKey bool) {

	ctx, cancel := context.WithTimeout(context.Background(), d)
	defer cancel()
	defer display.Forth.Send("AC@ .")

	for {
		select {
		case <-ctx.Done():

			hasKey = false

			return
		default:
			{
				res, err := display.Forth.Send(c.FORTH_BTN_PRESSED)

				if err != nil {

					continue
				}

				if res[0] != '0' {

					hasKey = true

					return
				}
			}
		}
	}
}

func (display *SerialDisplay) SwitchScreens() (n int) {

	// TODO: onrelease actions

	res, err := display.Forth.Send("AC@ .") // fetch action

	log.Println(res, err)

	if err != nil {

		return
	}

	if len(res) < 2 {
		return
	}

	// defer display.Forth.Send("0 2 w23") // store 0 to Action

	log.Println(res)

	n64, err := strconv.ParseInt(strings.TrimSpace(res[:2]), 16, 8)

	if err != nil {
		return
	}

	n = int(n64)

	if n == 0 {
		return
	}

	if n >= 0x60 {

		n = (n & 0x0F)

		log.Println("Selecting screen: ", n)

		return
	}

	log.Println("Pressed!")

	display.action = Action(n)

	n = 0

	return
}
