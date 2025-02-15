// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/fullscreen/main.go

#include <chrono>
#include <exception>
#include <print>
#include <utility>

import charm;

namespace tea = bubbletea;

namespace
{

enum model : int
{
};

using tickMsg = std::time_t;

auto tick() -> tea::Cmd
{
	return tea::Tick(std::chrono::seconds(1), [] { return tickMsg{}; });
}

auto Init(model /*m*/) -> tea::Cmd
{
	return tick();
}

auto Update(model& m, tea::Msg msg) -> tea::Cmd
{
	return utils::VisitMsg(
	    msg,
	    [](const tea::KeyMsg& keyMsg) -> tea::Cmd {
		    if (auto str = keyMsg.String(); str == "q" || str == "esc" || str == "ctrl+c")
		    {
			    return tea::Quit;
		    }
		    return {};
	    },
	    [&](tickMsg) -> tea::Cmd {
		    m = model(m - 1);

		    if (m <= 0)
		    {
			    return tea::Quit;
		    }

		    return tick();
	    }
	);
}

auto View(model m) -> std::string
{
	return std::format(
	    "\n\n     Hi. This program will exit in {} seconds...", std::to_underlying(m)
	);
}

}

auto main() -> int
{
	try
	{
		auto mod = model(5);
		utils::FreeStandingModelWrapper wrapper(mod);
		tea::NewProgram(wrapper, tea::WithAltScreen())
		    .Run()
		    .transform_error(utils::ThrowGoError)
		    .value();
	}
	catch (const std::exception& e)
	{
		std::println("Fatal: {}", e.what());
		return 1;
	}
}
