// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/debounce/main.go

#include <chrono>
#include <print>

import charm;

namespace tea = bubbletea;

constexpr auto debounceDuration = std::chrono::seconds(1);

using exitMsg = int;

struct model : tea::ModelBase
{
	int tag = 0;

	auto Init() -> tea::Cmd override
	{
		return {};
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(
		    msg,
		    [&](const tea::KeyMsg& /*keyMsg*/) -> tea::Cmd {
			    tag++;
			    return tea::Tick(debounceDuration, [tag = tag] -> tea::Msg {
				    return exitMsg(tag);
			    });
		    },
		    [&](const exitMsg& exitMsg) -> tea::Cmd {
			    if (exitMsg == tag)
			    {
				    return tea::Quit;
			    }
			    return {};
		    }
		);
	}

	auto View() -> std::string override
	{
		return std::format("Key presses: {}", tag) +
		       "\nTo exit press any key, then wait for one second without pressing anything.";
	}
};

auto main() -> int
{
	try
	{
		model mod;
		tea::NewProgram(mod).Run().transform_error(utils::ThrowGoError).value();
	}
	catch (const std::exception& e)
	{
		std::println("uh oh: {}", e.what());
		return 1;
	}
}
