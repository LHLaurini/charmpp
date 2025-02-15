module;

#include "libcharm++go.h"
#include <format>

export module charm:bubbletea.standard_renderer;

import :go;
import :bubbletea.tea;
import :bubbletea.standard_renderer.detail;
import :utils.detail;

export namespace bubbletea
{

template <std::formattable<char>... Args>
auto Println(Args&&... args) -> Cmd
{
	return [string = JoinFormattables(std::forward<Args>(args)...)] -> InternalMsg {
		return { utils::CgoCall(::Println, string) };
	};
}

template <std::formattable<char>... Args>
auto Print(std::format_string<Args...> format, Args&&... args) -> Cmd
{
	return Println(std::format(format, std::forward<Args>(args)...));
}

}

export template <go::StringerLike T>
// NOLINTNEXTLINE(cert-dcl58-cpp)
struct std::formatter<T, char> : std::formatter<std::string, char>
{
	auto format(const T& stringer, auto& ctx) const
	{
		return std::formatter<std::string, char>::format(stringer.String(), ctx);
	}
};
