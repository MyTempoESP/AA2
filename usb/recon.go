package usb

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"sync"
	"time"
)

type USBObserver struct {
	mu     sync.Mutex
	device string
}

func NewUSBObserver() (observer USBObserver) {

	go func() {

		<-time.After(5 * time.Second)

		observer.mu.Lock()
		observer.device, _ = GetUSBStorageDevice()
		observer.mu.Unlock()
	}()

	return
}

func (observer *USBObserver) Get() string {

	observer.mu.Lock()
	defer observer.mu.Unlock()

	return observer.device
}

func GetUSBStorageDevice() (device string, err error) {

	const sysBlockPath = "/sys/block/"

	// Read the contents of /sys/block
	blockDevices, err := os.ReadDir(sysBlockPath)

	if err != nil {

		err = fmt.Errorf("failed to read %s: %w", sysBlockPath, err)

		return
	}

	for _, dev := range blockDevices {

		var realPath string

		if !dev.IsDir() {

			continue
		}

		devicePath := filepath.Join(sysBlockPath, dev.Name())
		deviceFile := filepath.Join(devicePath, "device")
		realPath, err = filepath.EvalSymlinks(deviceFile)

		// USB devices will have "usb" in their symlink path
		if err == nil && strings.Contains(realPath, "/usb") {

			device = "/dev/" + dev.Name()

			return
		}
	}

	return
}
