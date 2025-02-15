package main

// #include "interop.h"
import "C"

import (
	"errors"
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
	case tea.BlurMsg:
		return C.MsgTypeBlur
	case tea.FocusMsg:
		return C.MsgTypeFocus
	case tea.InterruptMsg:
		return C.MsgTypeInterrupt
	case tea.KeyMsg:
		return C.MsgTypeKey
	case tea.MouseMsg:
		return C.MsgTypeMouse
	case tea.ResumeMsg:
		return C.MsgTypeResume
	case tea.SuspendMsg:
		return C.MsgTypeSuspend
	case tea.QuitMsg:
		return C.MsgTypeQuit
	case tea.WindowSizeMsg:
		return C.MsgTypeWindowSize
	default:
		return C.MsgTypeUnknown
	}
}

func valueFromMsg(msg tea.Msg) C.uintptr_t {
	switch msg := msg.(type) {
	case C.uintptr_t:
		return msg
	case tea.BlurMsg:
		return 0
	case tea.FocusMsg:
		return 0
	case tea.InterruptMsg:
		return 0
	case tea.KeyMsg:
		return toCppKey(tea.Key(msg))
	case tea.MouseMsg:
		return toCppMouseEvent(tea.MouseEvent(msg))
	case tea.ResumeMsg:
		return 0
	case tea.SuspendMsg:
		return 0
	case tea.QuitMsg:
		return 0
	case tea.WindowSizeMsg:
		return toCppWindowSizeMsg(msg)
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

		case C.MsgTypeInternal:
			fallthrough
		case C.MsgTypeKey:
			fallthrough
		case C.MsgTypeMouse:
			fallthrough
		case C.MsgTypeWindowSize:
			handle := cgo.Handle(msg.Msg)
			goMsg := handle.Value().(tea.Msg)
			handle.Delete()
			return goMsg

		case C.MsgTypeBlur:
			return tea.BlurMsg{}

		case C.MsgTypeFocus:
			return tea.FocusMsg{}

		case C.MsgTypeInterrupt:
			return tea.InterruptMsg{}

		case C.MsgTypeQuit:
			return tea.Quit()

		case C.MsgTypeResume:
			return tea.ResumeMsg{}

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

func fromCppMouseEvent(mouseEvent C.InterMouseEvent) tea.MouseEvent {
	return tea.MouseEvent{
		X:      int(mouseEvent.X),
		Y:      int(mouseEvent.Y),
		Shift:  bool(mouseEvent.Shift),
		Alt:    bool(mouseEvent.Alt),
		Ctrl:   bool(mouseEvent.Ctrl),
		Action: tea.MouseAction(mouseEvent.Action),
		Button: tea.MouseButton(mouseEvent.Button),
		Type:   0,
	}
}

func fromCppWindowSizeMsg(windowSizeMsg C.WindowSizeMsg) tea.WindowSizeMsg {
	return tea.WindowSizeMsg{
		Width:  int(windowSizeMsg.Width),
		Height: int(windowSizeMsg.Height),
	}
}

func toCppMouseEvent(mouseEvent tea.MouseEvent) C.uintptr_t {
	return C.toCppMouseEvent(C.InterMouseEvent{
		X:      C.int(mouseEvent.X),
		Y:      C.int(mouseEvent.Y),
		Shift:  C.bool(mouseEvent.Shift),
		Alt:    C.bool(mouseEvent.Alt),
		Ctrl:   C.bool(mouseEvent.Ctrl),
		Action: C.int(mouseEvent.Action),
		Button: C.int(mouseEvent.Button),
	})
}

func toCppWindowSizeMsg(windowSizeMsg tea.WindowSizeMsg) C.uintptr_t {
	return C.toCppWindowSizeMsg(C.WindowSizeMsg{
		Width:  C.int(windowSizeMsg.Width),
		Height: C.int(windowSizeMsg.Height),
	})
}

//export ToGoKey
func ToGoKey(key C.CppKey) goObject {
	return toGoObject(fromCppKey(key))
}

//export ToGoMouseEvent
func ToGoMouseEvent(mouseEvent C.InterMouseEvent) goObject {
	return toGoObject(fromCppMouseEvent(mouseEvent))
}

//export ToGoWindowSizeMsg
func ToGoWindowSizeMsg(windowSizeMsg C.WindowSizeMsg) goObject {
	return toGoObject(fromCppWindowSizeMsg(windowSizeMsg))
}

//export Println
func Println(str *C.char, length C.int) goObject {
	return toGoObject(tea.Println(C.GoStringN(str, length))())
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

//export IdentifyError
func IdentifyError(handle goObject) C.Err {
	err := cgo.Handle(handle).Value().(error)
	if errors.Is(err, tea.ErrProgramKilled) {
		return C.ErrProgramKilled
	} else if errors.Is(err, tea.ErrInterrupted) {
		return C.ErrInterrupted
	}
	return C.ErrUnknown
}
