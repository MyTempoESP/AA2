package mount

import (
	"errors"
	"log"

	"golang.org/x/sys/unix"
)

func Mount(device, mountPoint, fsType string) (err error) {

	flags := 0
	data := "" // (e.g., "uid=1000,gid=1000")

	if err = unix.Mkdir(mountPoint, 0755); err != nil && !errors.Is(err, unix.EEXIST) {

		log.Printf("Failed to create mount point: %v", err)

		return
	}

	if err = unix.Mount(device, mountPoint, fsType, uintptr(flags), data); err != nil {

		log.Printf("Failed to mount device: %v", err)

		return
	}

	log.Printf("Successfully mounted %s -> %s", device, mountPoint)

	return
}
