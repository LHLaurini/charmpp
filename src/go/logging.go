package main

// #include "interop.h"
import "C"

import tea "github.com/charmbracelet/bubbletea"

//export LogToFile
func LogToFile(path *C.char, pathLen C.int, prefix *C.char, prefixLen C.int) (bool, goObject) {
	file, err := tea.LogToFile(C.GoStringN(path, pathLen), C.GoStringN(prefix, prefixLen))

	if err == nil {
		return true, toGoObject(file)
	} else {
		return false, toGoObject(err)
	}
}
