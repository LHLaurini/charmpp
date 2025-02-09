module;

#include "libcharm++go.h"
#include <expected>
#include <string_view>
#include <type_traits>
#include <utility>

export module charm:bubbletea.logging;

import :go;
import :utils;

export namespace bubbletea
{

[[nodiscard]] auto LogToFile(std::string_view path, std::string_view prefix)
    -> std::expected<go::File, go::error>
{
	auto [success, value] = utils::CgoCall(::LogToFile, path, prefix);

	if (success == 0)
	{
		return std::unexpected<go::error>(value);
	}

	static_assert(std::is_constructible_v<go::File, go::File&&>);

	return std::expected<go::File, go::error>{ std::in_place, value };
}

}
