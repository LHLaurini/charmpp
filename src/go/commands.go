package main

// #include "interop.h"
import "C"

import (
	"time"
	"unsafe"

	tea "github.com/charmbracelet/bubbletea"
)

func makeCmdSlice(cmds *C.uintptr_t, numCmds C.int) []tea.Cmd {
	slice := make([]tea.Cmd, numCmds)

	for i := range slice {
		slice[i] = makeCmd(unsafe.Slice(cmds, numCmds)[i])
	}

	return slice
}

//export Batch
func Batch(cmds *C.uintptr_t, numCmds C.int) goObject {
	return toGoObject(tea.Batch(makeCmdSlice(cmds, numCmds)...)())
}

//export Sequence
func Sequence(cmds *C.uintptr_t, numCmds C.int) goObject {
	return toGoObject(tea.Sequence(makeCmdSlice(cmds, numCmds)...)())
}

//export SetWindowTitle
func SetWindowTitle(title *C.char, titleLen C.int) goObject {
	return toGoObject(tea.SetWindowTitle(C.GoStringN(title, titleLen))())
}

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
