package main

import (
	"embed"
	"fmt"
	"log"
	"os"
	"iota/create"
)

//go:embed project.layouts/c/*
var cProject embed.FS

func main() {
	if len(os.Args) < 3 {
		fmt.Println("iota: fatal: not enough arguments.\nusage: iota <language> <name>")
		return
	} else if len(os.Args) != 3 {
		fmt.Println("iota: fatal: incorrect arguments.\nusage: iota <language> <name>")
		return
	}
	Create(name, lang)
}
