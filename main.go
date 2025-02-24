package main

import (
	"embed"
	"fmt"
	"log"
	"os"
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
	name := os.Args[1]
	// lang := os.Args[2]
	err := os.Mkdir(name, 0644)
	if err != nil {
		log.Fatal(err)
	}
}
