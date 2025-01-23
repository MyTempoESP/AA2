package usb

import (
	"os/exec"
)

func Mount(device, mountPoint string) (err error) {

	args := []string{device, mountPoint}
	cmd := exec.Command("mount", args...)

	err = cmd.Run()

	return
}
