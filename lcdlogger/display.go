package lcdlogger

import (
	"log"
	"time"

	"github.com/MyTempoesp/flick"
)

type SerialDisplay struct {
	Forth *flick.MyTempo_Forth

	Screen int
	action int

	actionButtonLHTime time.Time // Last Held Timestamp
	actionButtonHeld   bool
}

func NewSerialDisplay() (display SerialDisplay, err error) {

	f, err := flick.NewForth("/dev/ttyUSB0")

	if err != nil {

		log.Printf("Erro ao iniciar a comunicação com o arduino: %v\n", err)

		return
	}

	f.Start()

	f.Query("1 .")

	f.Send("VAR bac")
	f.Send("VAR bst")
	f.Send(": btn 7 IN 0 = ;")
	f.Send(": chb bac @ NOT IF bst @ btn DUP ROT SWP NOT AND bac ! bst ! THN ;")
	f.Send("10 0 TMI chb 1 TME")

	display.Forth = &f
	display.action = -1

	return
}

func (display *SerialDisplay) SwitchScreens() {

	// TODO: onrelease actions

	res, err := display.Forth.Send("bac @ .")

	if err != nil {

		return
	}

	defer display.Forth.Send("0 bac !")

	if res[0] == '-' { // onrelease

		display.actionButtonHeld = false // button released

		lht := display.actionButtonLHTime

		log.Println("Release detected: ", time.Now(), lht)

		if time.Now().After(lht.Add(time.Millisecond * 700)) { // XXX: magic number

			display.action = display.Screen

			return
		}

		display.Screen++
		display.Screen %= SCREEN_COUNT
	}
}

func (display *SerialDisplay) Action() (action int, hasAction bool) {

	action = display.action

	if action >= 0 {

		hasAction = true
		display.action = -1
	}

	return
}

func (display *SerialDisplay) hasAction() bool {

	return display.action >= 0
}

func (display *SerialDisplay) HandleActionButton() {

	if display.actionButtonHeld {

		return
	}

	if display.hasAction() {

		return
	}

	res, err := display.Forth.Send("bst @ .")

	if err != nil {

		return
	}

	if res[0] == '-' {

		log.Println("Click detected: ", time.Now())

		display.actionButtonLHTime = time.Now()
		display.actionButtonHeld = true
	}
}
