package main

// #include "interop.h"
import "C"

import (
	"fmt"
	"os"
	"runtime/cgo"
	"unsafe"

	tea "github.com/charmbracelet/bubbletea"
)

func typeFromMsg(msg tea.Msg) C.MsgType {
	switch msg.(type) {
	case tea.KeyMsg:
		return C.MsgTypeKey
	case C.uintptr_t:
		return C.MsgTypeUser
	default:
		return C.MsgTypeUnknown
	}
}

func valueFromMsg(msg tea.Msg) C.uintptr_t {
	switch msg := msg.(type) {
	case C.uintptr_t:
		return msg
	default:
		return C.uintptr_t(toGoObject(msg))
	}
}

func makeCmd(cmdID C.uintptr_t) tea.Cmd {
	if cmdID == 0 {
		return nil
	}

	return func() tea.Msg {
		msg := C.callAndDestroyCmd(cmdID)

		if msgHandle := C.getMsgIfGoObject(msg); msgHandle != 0 {
			goMsg := cgo.Handle(msgHandle).Value().(tea.Msg)
			C.destroyMsg(msg)
			return goMsg
		}

		return msg
	}
}

func fromCppString(id C.uintptr_t) string {
	str := C.GoStringN(C.stringData(id), C.stringSize(id))
	C.destroyString(id)
	return str
}

//export ToCppString
func ToCppString(str goObject, stringPtr unsafe.Pointer) {
	C.toCppString(cgo.Handle(str).Value().(string), stringPtr)
}

//export Error
func Error(err goObject) goObject {
	return toGoObject(cgo.Handle(err).Value().(error).Error())
}

//export String
func String(obj goObject) goObject {
	return toGoObject(cgo.Handle(obj).Value().(fmt.Stringer).String())
}

//export FileClose
func FileClose(object goObject) {
	cgo.Handle(object).Value().(*os.File).Close()
}

//export DeleteHandle
func DeleteHandle(handle goObject) {
	cgo.Handle(handle).Delete()
}
