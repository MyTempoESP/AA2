package lcdlogger

import (
	"context"
	"log"
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

	f, err := flick.NewForth("/dev/ttyUSB0")

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
	defer display.Forth.Send("0 v49 !")

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

func (display *SerialDisplay) SwitchScreens() {

	// TODO: onrelease actions

	res, err := display.Forth.Send("v49 @ .")

	if err != nil {

		return
	}

	defer display.Forth.Send("0 v49 !")

	if res[:2] == "24" {
		log.Println("Switching screen: ")

		display.Screen = int(res[3]) + int('0')

		return
	} else {
		log.Println("Pressed!")

		display.action = Action(res[2])
	}
}
