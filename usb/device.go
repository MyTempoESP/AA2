package usb

import (
	"errors"
)

type Device struct {
	Name      string
	FS        FileSystem
	IsMounted bool
}

func (d *Device) Mount(mountPoint string) (err error) {

	if d.IsMounted {

		err = errors.New("Device already mounted!")

		return
	}

	err = Mount(d.Name, mountPoint)

	if err != nil {

		return
	}

	d.IsMounted = true

	return
}

func (d *Device) Check() (check bool, err error) {

	d.Name, check, err = CheckUSBStorageDevice(d.FS)

	return
}
