package usb

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"sync"
	"time"
)

// Cache structure for storing USB device data
type USBDeviceCache struct {
	mu         sync.RWMutex
	device     string
	lastUpdate time.Time
	ttl        time.Duration
}

// NewUSBDeviceCache creates a new cache instance
func NewUSBDeviceCache(ttl time.Duration) *USBDeviceCache {

	return &USBDeviceCache{
		lastUpdate: time.Time{},
		ttl:        ttl,
	}
}

// Get retrieves cached data if valid, otherwise refreshes it
func (cache *USBDeviceCache) Get() (device string, err error) {

	cache.mu.RLock()

	device = cache.device

	if time.Since(cache.lastUpdate) < cache.ttl {

		// Return cached devices if the cache is still valid
		defer cache.mu.RUnlock()

		return
	}

	cache.mu.RUnlock()

	// Refresh the cache
	cache.mu.Lock()

	defer cache.mu.Unlock()

	// Prevent concurrent refreshes
	if time.Since(cache.lastUpdate) < cache.ttl {

		return
	}

	// Fetch fresh data
	device, err = GetUSBStorageDevice()

	if err != nil {

		return
	}

	cache.device = device
	cache.lastUpdate = time.Now()

	return
}

// GetUSBStorageDevicesDetails returns details about USB storage devices connected to the system.
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
