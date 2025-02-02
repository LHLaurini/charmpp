package main

// #include "interop.h"
import "C"

import "runtime/cgo"

type goObject C.uintptr_t

func toGoObject(object any) goObject {
	return goObject(cgo.NewHandle(object))
}

func toGoObjectOrZero(object any) goObject {
	if object != nil {
		return goObject(cgo.NewHandle(object))
	} else {
		return 0
	}
}
