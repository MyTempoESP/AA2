package main

import (
	"log"
	"os"
	"sync/atomic"
	"time"

	"analytics/intSet"
	"analytics/lcdlogger"
	"github.com/MyTempoesp/flick"
	"github.com/prometheus-community/pro-bing"
)

func (a *Ay) Process() {

	var (
		tags     atomic.Int64
		antennas [4]atomic.Int64
	)

	tagSet := intSet.New()

	go func() {

		for t := range a.Tags {

			if t.Antena == 0 {
				/*
					Antena 0 não exist
				*/

				continue
			}

			antennas[(t.Antena-1)%4].Add(1)

			tags.Add(1)

			tagSet.Insert(t.Epc)
		}
	}()

	/*
		Resetting the tags:

		TODO: add a clear method of
		resetting tags on the database

		tagSet.Clear()
		tags.Store(0)
		for i := range 4 {
			antennas[i].Store(0)
		}

	*/

	var readerIP = os.Getenv("READER_IP")
	var readerOctets = lcdlogger.IPIfy(readerIP)

	var readerState atomic.Bool
	var readerPing atomic.Int64

	display, displayErr := lcdlogger.NewSerialDisplay()

	/* > Monitoring can be skipped if NewSerialDisplay() errors out, disabling the routine in Line 221 */
	if displayErr != nil {

		return
	}

	go func() {

		p, err := probing.NewPinger(readerIP)

		//p.SetPrivileged(true)

		if err != nil {

			return
		}

		p.Count = 0xFFFE
		p.Interval = 4 * time.Second

		p.OnSend = func(pkt *probing.Packet) {

			log.Printf("IP Addr: %s\n", pkt.IPAddr)

			readerState.Store(false)
		}

		p.OnRecv = func(pkt *probing.Packet) {

			log.Printf("IP Addr: %s receive, RTT: %v\n", pkt.IPAddr, pkt.Rtt)

			readerState.Store(true)
			readerPing.Store(pkt.Rtt.Milliseconds())
		}

		p.Run()
	}()

	go func() {

		const NUM_EQUIP = 701

		for {

			commVerif := flick.WEB

			switch display.Screen {
			case lcdlogger.SCREEN_TAGS:
				display.ScreenTags(
					NUM_EQUIP,
					commVerif,
					/* Tags */ tags.Load(),
					/* Atletas */ tagSet.Count(),
				)
			case lcdlogger.SCREEN_ADDR:

				ok := flick.OK

				if !readerState.Load() {

					ok = flick.DESLIGAD
				}

				display.ScreenAddr(
					NUM_EQUIP,
					commVerif,
					readerPing.Load(),
					/* IP */ readerOctets,
					/* leitor OK? */ ok,
				)
			case lcdlogger.SCREEN_WIFI:
				display.ScreenWifi(
					NUM_EQUIP,
					commVerif,
					/* WIFI */ flick.CONECTAD,
					/* 4G */ flick.DESLIGAD,
				)
			case lcdlogger.SCREEN_STAT:
				display.ScreenStat(
					NUM_EQUIP,
					commVerif,
					lcdlogger.ToForthNumber(antennas[0].Load()),
					lcdlogger.ToForthNumber(antennas[1].Load()),
					lcdlogger.ToForthNumber(antennas[2].Load()),
					lcdlogger.ToForthNumber(antennas[3].Load()),
				)
			}

			display.SwitchScreens()

			time.Sleep(100 * time.Millisecond)
		}
	}()
}
