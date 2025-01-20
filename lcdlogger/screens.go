package lcdlogger

import (
	"fmt"
	"time"

	"github.com/MyTempoesp/flick"
)

const (
	SCREEN_TAGS = iota
	SCREEN_ADDR
	SCREEN_WIFI
	SCREEN_STAT
	SCREEN_TIME
	SCREEN_USB

	SCREEN_COUNT
)

type IPOctets [4]int

func (display *SerialDisplay) ScreenTags(nome, commVerif int, tags, tagsUnicas int64) {

	display.Forth.Send(
		fmt.Sprintf(
			"%d lbl %d num"+
				" %d lbl %d num"+
				" %d lbl %d num"+
				" %d lbl %d val",

			flick.PORTAL, nome,
			flick.REGIST, tags,
			flick.UNICAS, tagsUnicas,
			flick.COMUNICANDO, commVerif,
		),
	)
}

func (display *SerialDisplay) ScreenAddr(nome, commVerif int, ip IPOctets, leitorOk int) {

	display.Forth.Send(
		fmt.Sprintf(
			"%d lbl %d num"+
				" %d lbl %d %d %d %d ip"+
				" %d lbl %d val"+
				" %d lbl %d val",

			flick.PORTAL, nome,
			flick.IP, ip[3], ip[2], ip[1], ip[0],
			flick.LEITOR, leitorOk,
			flick.COMUNICANDO, commVerif,
		),
	)
}

func (display *SerialDisplay) ScreenWifi(nome, commVerif, wifiVerif, LTE4GVerif int, wifiPing int64) {

	display.Forth.Send(
		fmt.Sprintf(
			"%d lbl %d num"+
				" %d lbl %d val"+
				" %d lbl %d val"+
				" %d lbl %d ms",

			flick.PORTAL, nome,
			flick.WIFI, wifiVerif,
			flick.LTE4G, LTE4GVerif,
			flick.PING, wifiPing,
		),
	)
}

func (display *SerialDisplay) ScreenStat(nome, commVerif int, a1, a2, a3, a4 ForthNumber) {

	display.Forth.Send(
		fmt.Sprintf(
			"%d lbl %d num"+
				" %d %d"+ // A4 Val+Mag
				" %d %d"+ // A3 Val+Mag
				" %d %d"+ // A2 Val+Mag
				" %d %d atn"+ // A1 Val+Mag then display
				" %d lbl %d val",

			flick.PORTAL, nome,
			a4.Value, a4.Magnitude,
			a3.Value, a3.Magnitude,
			a2.Value, a2.Magnitude,
			a1.Value, a1.Magnitude,
			flick.COMUNICANDO, commVerif,
		),
	)
}

func (display *SerialDisplay) ScreenTime(nome, commVerif int) {

	now := time.Now()

	display.Forth.Send(
		fmt.Sprintf(
			"%d lbl %d num"+
				" tim %d %d"+
				" %d 3 - hms"+ // We at GMT-3
				" <cr>"+
				" %d lbl %d val",

			flick.PORTAL, nome,
			now.Second(), now.Minute(), now.Hour(),
			flick.COMUNICANDO, commVerif,
		),
	)
}

// interactive shit
func (display *SerialDisplay) ScreenUSB(nome, commVerif int) {

	now := time.Now()

	display.Forth.Send(
		fmt.Sprintf(
			"%d lbl %d num"+
				" tim %d %d %d hms"+
				" 6 lbl %d num"+
				" %d lbl %d val",

			flick.PORTAL, nome,
			now.Second(), now.Minute(), now.Hour(),
			now.Day(),
			flick.COMUNICANDO, commVerif,
		),
	)
}

func (display *SerialDisplay) ToggleDialog() {

	display.Forth.Send(
		"dia @ NOT dia !", // dia (DIAlog) @ (fetch var) NOT dia ! (set var)
	)
}

func (display *SerialDisplay) ScreenYN() {

	display.Forth.Send(
		"<cr> ask fwd as2 <cr>",
	)
}
