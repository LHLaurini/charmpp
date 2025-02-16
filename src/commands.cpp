module;

#include "libcharm++go.h"
#include <chrono>
#include <concepts>
#include <functional>
#include <ranges>

export module charm:bubbletea.commands;

import :go;
import :bubbletea.tea;
import :interop.detail;
import :utils;

export namespace bubbletea
{

template <typename T>
concept RangeOfMovableCmd = std::ranges::range<T> && !std::ranges::constant_range<T> &&
                            std::same_as<std::ranges::range_value_t<T>, Cmd>;

// Happens to be the same as Cmd
using TickCallback = std::function<Msg()>;

template <RangeOfMovableCmd R>
auto Batch(R cmds) -> Cmd
{
	return [cmds = std::ranges::to<std::vector>(
	            cmds | std::views::as_rvalue | std::views::transform(StowCmd)
	        )] { return InternalMsg{ utils::CgoCall(::Batch, cmds) }; };
};

template <typename... Cmds>
requires(std::constructible_from<Cmd, Cmds> && ...)
auto Batch(Cmds... cmds) -> Cmd
{
	return Batch(std::array{ Cmd{ std::move(cmds) }... });
};

template <RangeOfMovableCmd R>
auto Sequence(R cmds) -> Cmd
{
	return [cmds = std::ranges::to<std::vector>(
	            cmds | std::views::as_rvalue | std::views::transform(StowCmd)
	        )] { return InternalMsg{ utils::CgoCall(::Sequence, cmds) }; };
};

template <typename... Cmds>
requires(std::constructible_from<Cmd, Cmds> && ...)
auto Sequence(Cmds... cmds) -> Cmd
{
	return Sequence(std::array{ Cmd{ std::move(cmds) }... });
};

auto SetWindowTitle(std::string title) -> Cmd
{
	return [title = std::move(title)] -> InternalMsg {
		return { utils::CgoCall(::SetWindowTitle, title) };
	};
}

auto Tick(std::chrono::nanoseconds duration, TickCallback callback) -> Cmd
{
	return [callback = std::move(callback), duration] -> Msg {
		::Tick(duration.count());
		return callback();
	};
}

auto WindowSize() -> Cmd
{
	return [] -> InternalMsg { return { utils::CgoCall(::WindowSize) }; };
}

}
