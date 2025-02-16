module;

#include "libcharm++go.h"
#include <chrono>
#include <functional>

export module charm:bubbletea.commands;

import :go;
import :bubbletea.tea;
import :utils;

export namespace bubbletea
{

// Happens to be the same as Cmd
using TickCallback = std::function<Msg()>;

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
