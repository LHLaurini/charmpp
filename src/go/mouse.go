package main

// #include "interop.h"
import "C"

import (
	"runtime/cgo"

	tea "github.com/charmbracelet/bubbletea"
)

//export IsWheel
func IsWheel(event goObject) bool {
	return cgo.Handle(event).Value().(tea.MouseEvent).IsWheel()
}
