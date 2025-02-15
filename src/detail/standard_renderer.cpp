module;

#include "libcharm++go.h"
#include <format>
#include <string>
#include <string_view>

export module charm:bubbletea.standard_renderer.detail;

namespace bubbletea
{

// Match the behavior of fmt.Sprint (add spaces between arguments except when both are strings)
template <std::formattable<char>... Args>
auto JoinFormattables(Args&&... args)
{
	std::string result;
	std::string_view separator;
	bool first = true;
	bool stringLike{};
	bool lastArgWasStringLike = false;

	((stringLike = std::constructible_from<std::string, Args>,
	  separator = !first && !(stringLike && lastArgWasStringLike) ? " " : "",
	  std::format_to(std::back_inserter(result), "{}{}", separator, std::forward<Args>(args)),
	  lastArgWasStringLike = stringLike, first = false),
	 ...);

	return result;
}

}
