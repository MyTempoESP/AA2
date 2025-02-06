package constant

import (
	"os"
	"time"
)

var (
	ProgramTimezone, _ = time.LoadLocation("Brazil/East")
	Version            = os.Getenv("PROGRAM_COMMIT_HASH")[:4]
	Serie              = 501
)
