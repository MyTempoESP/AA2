package lcdlogger

import (
	"log"

	"github.com/MyTempoesp/flick"
)

type SerialDisplay struct {
	Forth  *flick.MyTempo_Forth
	Screen int

	action int

	switchButtonToggled bool
	actionButtonHeld    bool
}

//func newForth() (f *flick.MyTempo_Forth, err error) {
//
//forth, err := flick.NewForth("/dev/ttyUSB1")
//
//if err != nil {
//
//goto USB0
//}
//
//f = &forth
//
//USB0:
//forth, err = flick.NewForth("/dev/ttyUSB0")
//
//if err != nil {
//
//return
//}
//
//f = &forth
//
//return
//}

func NewSerialDisplay() (display SerialDisplay, err error) {

	f, err := flick.NewForth("/dev/ttyUSB0")

	if err != nil {

		log.Printf("Erro ao iniciar a comunicação com o arduino: %v\n", err)

		return
	}

	f.Start()

	f.Query("WRD")

	display.Forth = &f

	f.Send("VAR bac")
	f.Send("VAR bst")
	f.Send(": btn 7 IN 0 = ;")
	f.Send(": chb bac @ NOT IF bst @ btn DUP ROT SWP NOT AND bac ! bst ! THN ;")
	f.Send("10 0 TMI chb 1 TME")

	return
}

func (display *SerialDisplay) SwitchScreens() {

	// TODO: onrelease actions

	res, err := display.Forth.Send("bac @ .")
	defer display.Forth.Send("0 bac !")

	if err != nil {

		return
	}

	if res[0] == '-' && !display.switchButtonToggled { // onrelease

		display.Screen++
		display.Screen %= 5

		//display.switchButtonToggled = true
		display.actionButtonHeld = false // button released
	}

	/*if res[0] == '0' && display.switchButtonToggled {

		display.switchButtonToggled = false
	}*/
}

func (display *SerialDisplay) Action() (action int, hasAction bool) {

	action = display.action
	hasAction = display.action != -1

	return
}

func (display *SerialDisplay) SetAction() {

	if _, hasAction := display.Action(); hasAction {

		return
	}

	if display.actionButtonHeld {

		return
	}

	res, err := display.Forth.Send("bst @ .")

	if err != nil {

		return
	}

	if res[0] == '-' {

		display.actionButtonHeld = true
	}
}
