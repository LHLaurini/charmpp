package main

// #include "interop.h"
import "C"

import (
	tea "github.com/charmbracelet/bubbletea"
)

//export WithMouseAllMotion
func WithMouseAllMotion() goObject {
	return toGoObject(tea.WithMouseAllMotion())
}

//export WithReportFocus
func WithReportFocus() goObject {
	return toGoObject(tea.WithReportFocus())
}
