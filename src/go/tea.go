package main

// #include "interop.h"
import "C"

import (
	"runtime/cgo"
	"unsafe"

	tea "github.com/charmbracelet/bubbletea"
)

//export NewProgram
func NewProgram(modelPtr unsafe.Pointer) goObject {
	var model model
	model.modelPtr = modelPtr

	program := tea.NewProgram(model)

	return toGoObject(program)
}

//export ProgramRun
func ProgramRun(programObj goObject) goObject {
	_, err := cgo.Handle(programObj).Value().(*tea.Program).Run()
	return toGoObjectOrZero(err)
}

//export Quit
func Quit() goObject {
	return toGoObject(tea.Quit())
}

//export Suspend
func Suspend() goObject {
	return toGoObject(tea.Suspend())
}
