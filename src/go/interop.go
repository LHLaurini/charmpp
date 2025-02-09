package main

// #include "interop.h"
import "C"

import (
	"fmt"
	"log"
	"os"
	"runtime/cgo"
	"unsafe"

	tea "github.com/charmbracelet/bubbletea"
)

func typeFromMsg(msg tea.Msg) C.MsgType {
	switch msg.(type) {
	case C.uintptr_t:
		return C.MsgTypeUser
	case tea.KeyMsg:
		return C.MsgTypeKey
	case tea.SuspendMsg:
		return C.MsgTypeSuspend
	case tea.QuitMsg:
		return C.MsgTypeQuit
	default:
		return C.MsgTypeUnknown
	}
}

func valueFromMsg(msg tea.Msg) C.uintptr_t {
	switch msg := msg.(type) {
	case C.uintptr_t:
		return msg
	case tea.KeyMsg:
		return toCppKey(tea.Key(msg))
	case tea.SuspendMsg:
		return 0
	case tea.QuitMsg:
		return 0
	default:
		return 0
	}
}

func makeCmd(cmdID C.uintptr_t) tea.Cmd {
	if cmdID == 0 {
		return nil
	}

	return func() tea.Msg {
		msg := C.callAndDestroyCmd(cmdID)

		switch msg.Type {
		case C.MsgTypeUser:
			return msg.Msg

		case C.MsgTypeKey:
			handle := cgo.Handle(msg.Msg)
			goMsg := handle.Value().(tea.Msg)
			handle.Delete()
			return goMsg

		case C.MsgTypeQuit:
			return tea.Quit()

		case C.MsgTypeSuspend:
			return tea.Suspend()

		default:
			log.Fatal("unknown message type received")
			return 0
		}
	}
}

func fromCppString(id C.uintptr_t) string {
	str := C.GoStringN(C.stringData(id), C.stringSize(id))
	C.destroyString(id)
	return str
}

func fromCppKey(key C.CppKey) tea.Key {
	result := tea.Key{
		Type:  tea.KeyType(key.Type),
		Runes: make([]rune, key.NumRunes),
		Alt:   bool(key.Alt),
		Paste: bool(key.Paste),
	}

	// Make sure to copy the content (we need to convert C.char32_t to rune anyway)
	for i := range result.Runes {
		result.Runes[i] = rune(unsafe.Slice(key.Runes, key.NumRunes)[i])
	}

	return result
}

func fromCppKeyID(id C.uintptr_t) tea.Key {
	return fromCppKey(C.fromCppKey(id))
}

func toCppKey(key tea.Key) C.uintptr_t {
	var runes *C.rune

	if len(key.Runes) > 0 {
		runes = (*C.rune)(&key.Runes[0])
	} else {
		runes = nil
	}

	return C.toCppKey(C.GoKey{
		Type:     C.int(key.Type),
		Runes:    runes,
		NumRunes: C.unsigned(len(key.Runes)),
		Alt:      C.bool(key.Alt),
		Paste:    C.bool(key.Paste),
	})
}

//export ToGoKey
func ToGoKey(key C.CppKey) goObject {
	return toGoObject(fromCppKey(key))
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
