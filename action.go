package main

import (
	"fmt"
	"time"

	file "aa2/file"
	usb "aa2/usb"
)

func CopyToUSB(device usb.Device, file file.File) (err error) {

	if !device.IsMounted {

		err = device.Mount("/mnt")

		if err != nil {

			return
		}
	}

	file.Upload(fmt.Sprintf("/mnt/MYTEMPO-%v", time.Now().Format("2017_09_07_17_06_06_Wednesday")))

	return
}
