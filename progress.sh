# shellcheck shell=bash disable=SC2034

progress()
{
	package "Bubble Tea" bubbletea
		func LogToFile
			caveats
			note "<code>go::File</code> cannot be used from C++"
		type BatchMsg
			note "Use <code>Batch</code> instead"
		type BlurMsg
			implemented
		type Cmd
			implemented
		func Batch
			implemented
		type Printf
			implemented
			note "Implemented as <code>Print</code>, uses <code>std::format_string</code> instead of <code>printf</code>-style format strings"
		type Println
			implemented
		func Sequence
			implemented
		func SetWindowTitle
			implemented
		func Tick
			implemented
			note "Callback receives no arguments. Use <code>std::chrono</code> to get the time"
		func WindowSize
			implemented
		type FocusMsg
			implemented
		type InterruptMsg
			implemented
		type Key
			implemented
		func "(Key) String"
			implemented
		type KeyMsg
			implemented
			note "<code>KeyMsg</code> is an alias for <code>Key</code>"
		type "(KeyMsg) String"
			implemented
		type KeyType
			implemented
		type MouseAction
			implemented
		type MouseButton
			implemented
		type MouseEvent
			implemented
		func "(MouseEvent) IsWheel"
			implemented
		func "(MouseEvent) String"
			implemented
		type MouseMsg
			implemented
			note "<code>MouseMsg</code> is an alias for <code>MouseEvent</code>"
		func "(MouseMsg) String"
			implemented
		type Model
			implemented
		type Msg
			implemented
		func Interrupt
			implemented
		func Quit
			implemented
		func Suspend
			implemented
		type Program
			implemented
		func NewProgram
			implemented
		func "(*Program) Run"
			implemented
		type ProgramOption
			implemented
		func WithAltScreen
			implemented
		func WithMouseAllMotion
			implemented
		func WithReportFocus
			implemented
		type QuitMsg
			implemented
		type ResumeMsg
			implemented
		type SuspendMsg
			implemented
		type WindowSizeMsg
			implemented

	package Bubbles/cursor bubbles/cursor
	package Bubbles/filepicker bubbles/filepicker
	package Bubbles/help bubbles/help
	package Bubbles/key bubbles/key
	package Bubbles/list bubbles/list
	package Bubbles/paginator bubbles/paginator
	package Bubbles/progress bubbles/progress
	package Bubbles/runeutil bubbles/runeutil
	package Bubbles/spinner bubbles/spinner
	package Bubbles/stopwatch bubbles/stopwatch
	package Bubbles/table bubbles/table
	package Bubbles/textarea bubbles/textarea
	package Bubbles/textarea/memoization bubbles/textarea/memoization
	package Bubbles/textinput bubbles/textinput
	package Bubbles/timer bubbles/timer
	package Bubbles/viewport bubbles/viewport
	package Harmonica harmonica
	package "Lip Gloss" lipgloss
}
