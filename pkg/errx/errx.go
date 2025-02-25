package errx

import (
	"fmt"
	"os"
)

const usageMsg = "usage: iota <language> <name> [--git]"

func Errx(status int, usage bool, src string) {
	defer cleanup(usage)

	switch status {
	case 0:
		fmt.Printf("iota: %s\n", src)
		break
	case 1:
		fmt.Printf("iota: warning: %s\n", src)
		break
	case 2:
		fmt.Printf("iota: error: %s\n", src)
		break
	case 3:
		fmt.Printf("iota: fatal: %s\n", src)
		cleanup(usage)
		os.Exit(0)
	}
}

func cleanup(usage bool) {
	if usage {
		fmt.Println(usageMsg)
	}
}
