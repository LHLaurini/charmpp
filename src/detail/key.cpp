module;

#include "libcharm++go.h"
#include <string>

export module charm:bubbletea.key.detail;

import :go;
import :interop.detail;
import :bubbletea.key;

namespace tea = bubbletea;

[[nodiscard]] auto tea::Key::String() const -> std::string
{
	return go::Stringer(::ToGoKey(::FromCppKey(*this))).String();
}
