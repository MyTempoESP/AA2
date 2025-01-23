package file

import (
	"fmt"
	"io"
	"os"
)

func copyFile(src *os.File, dst string) error {

	// Create the destination file
	destinationFile, err := os.Create(dst)
	if err != nil {
		return fmt.Errorf("failed to create destination file: %v", err)
	}
	defer destinationFile.Close()

	// Copy the contents from source to destination
	_, err = io.Copy(destinationFile, src)
	if err != nil {
		return fmt.Errorf("failed to copy file: %v", err)
	}

	return nil
}
