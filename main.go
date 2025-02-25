package main

import (
	"os"
	"iota/pkg/errx"
	"iota/pkg/create"
)

func main() {
	if len(os.Args) < 3 {
		errx.Errx(3, true, "not enough arguments.")
		return
	} else if len(os.Args) != 3 {
		errx.Errx(3, true, "incorrect argument format.")
		return
	}
	create.Create(os.Args[1], os.Args[2])
}
