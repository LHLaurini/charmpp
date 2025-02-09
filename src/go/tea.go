package main

// #include "interop.h"
import "C"

import (
	"runtime/cgo"
	"unsafe"

	tea "github.com/charmbracelet/bubbletea"
)

//export NewProgram
func NewProgram(modelPtr unsafe.Pointer, opts *uintptr, numOpts uint) goObject {
	var model model
	model.modelPtr = modelPtr

	optSlice := unsafe.Slice(opts, numOpts)
	programOptions := make([]tea.ProgramOption, numOpts)

	for i, opt := range optSlice {
		programOptions[i] = cgo.Handle(opt).Value().(tea.ProgramOption)
	}

	program := tea.NewProgram(model, programOptions...)

	return toGoObject(program)
}

//export ProgramRun
func ProgramRun(programObj goObject) goObject {
	_, err := cgo.Handle(programObj).Value().(*tea.Program).Run()
	return toGoObjectOrZero(err)
}
