package main

// #include "interop.h"
import "C"

import (
	"time"

	tea "github.com/charmbracelet/bubbletea"
)

//export Tick
func Tick(durationNS int) {
	// We could have this function receive a C++ callback, but this is way simpler. Then we can
	// handle most things directly from the C++ side. Perhaps we could even just do everything from
	// the C++ side, including the waiting, but that probably wouldn't play nicely with bubbletea's
	// internal Goroutines.
	tea.Tick(time.Duration(durationNS), func(time.Time) tea.Msg { return nil })()
}

//export WindowSize
func WindowSize() goObject {
	return toGoObject(tea.WindowSize()())
}
