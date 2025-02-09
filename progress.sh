# shellcheck shell=bash disable=SC2034

progress()
{
	package "Bubble Tea" bubbletea
		func LogToFile
			caveats
			note "<code>go::File</code> cannot be used from C++"
		type Cmd
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
		type Model
			implemented
		type Msg
			implemented
		func Quit
			implemented
		func Suspend
			implemented
		type Program
			implemented
		func NewProgram
			partial
			note "<code>opts</code> parameter unimplemented"
		func "(*Program) Run"
			implemented
		type QuitMsg
			implemented
		type SuspendMsg
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
