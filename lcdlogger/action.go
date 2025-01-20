package lcdlogger

import (
	"log"
	"time"
)

const (
	ACTION_USB = iota
)

type Action int

func (display *SerialDisplay) Action() (action Action, hasAction bool) {

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

	res, err := display.Forth.Send("bst @ .") // ButtonSTate

	if err != nil {

		return
	}

	if res[0] == '-' {

		log.Println("Click detected: ", time.Now())

		display.actionButtonLHTime = time.Now()
		display.actionButtonHeld = true
	}
}

func (display *SerialDisplay) Do(action Action) {

	switch action {
	case ACTION_USB:

	}
}
