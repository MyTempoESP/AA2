package usb

import (
	"errors"
)

type Device struct {
	Name      string
	FS        FileSystem
	IsMounted bool
}

func (d *Device) Mount(mountPoint string) error {

	if d.IsMounted {

		return errors.New("Device already mounted!")
	}

	d.IsMounted = true

	return Mount(d.Name, mountPoint)
}

func (d *Device) Check() (bool, error) {

	return CheckUSBStorageDevice(d.FS)
}
