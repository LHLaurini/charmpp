package main

// #include "interop.h"
import "C"

import (
	"unsafe"

	tea "github.com/charmbracelet/bubbletea"
)

type model struct {
	modelPtr unsafe.Pointer
}

func (m model) Init() tea.Cmd {
	return makeCmd(C.callInit(m.modelPtr))
}

func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	cmdID := C.callUpdate(m.modelPtr, typeFromMsg(msg), valueFromMsg(msg))
	return m, makeCmd(cmdID)
}

func (m model) View() string {
	return fromCppString(C.callView(m.modelPtr))
}
