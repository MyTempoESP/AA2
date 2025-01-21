package usb

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"sync/atomic"
	"time"
)

type USBObserver struct {
	device atomic.Bool
}

func NewUSBObserver() (observer USBObserver) {

	go func() {

		<-time.After(5 * time.Second)
		hasDev, _ := CheckUSBStorageDevice()

		observer.device.Store(hasDev)
	}()

	return
}

func (observer *USBObserver) Get() bool {

	return observer.device.Load()
}

func CheckUSBStorageDevice() (check bool, err error) {

	const sysBlockPath = "/sys/block/"

	// Read the contents of /sys/block
	blockDevices, err := os.ReadDir(sysBlockPath)

	if err != nil {

		err = fmt.Errorf("failed to read %s: %w", sysBlockPath, err)

		return
	}

	for _, dev := range blockDevices {

		var realPath string

		devicePath := filepath.Join(sysBlockPath, dev.Name())
		deviceFile := filepath.Join(devicePath, "device")
		realPath, err = filepath.EvalSymlinks(deviceFile)

		// USB devices will have "usb" in their symlink path
		if err == nil && strings.Contains(realPath, "/usb") {

			//device = "/dev/" + dev.Name()
			check = true

			return
		}
	}

	return
}
