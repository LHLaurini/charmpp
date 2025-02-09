module;

#include "libcharm++go.h"
#include <string>

export module charm:bubbletea.mouse.detail;

import :go;
import :interop.detail;
import :bubbletea.mouse;

namespace tea = bubbletea;

[[nodiscard]] auto tea::MouseEvent::IsWheel() const -> bool
{
	go::GoObject self(::ToGoMouseEvent(::FromCppMouseEvent(*this)));
	return ::IsWheel(self.GetHandle()) != 0;
}

[[nodiscard]] auto tea::MouseEvent::String() const -> std::string
{
	return go::Stringer(::ToGoMouseEvent(::FromCppMouseEvent(*this))).String();
}
