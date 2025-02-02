// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/simple/main.go

#include <chrono>
#include <exception>
#include <print>
#include <thread>
#include <utility>

import charm;

namespace tea = bubbletea;

namespace
{

enum model : int
{
};

using tickMsg = std::time_t;

auto tick() -> tea::Msg
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return tickMsg{};
}

auto Init(model /*m*/) -> tea::Cmd
{
	return tick;
}

auto Update(model& m, tea::Msg msg) -> tea::Cmd
{
	return utils::VisitMsg(
	    msg,
	    [](const tea::KeyMsg& keyMsg) -> tea::Cmd {
		    auto str = keyMsg.String();

		    if (str == "ctrl+c" || str == "q")
		    {
			    return tea::Quit;
		    }

		    if (str == "ctrl+z")
		    {
			    return tea::Suspend;
		    }

		    return {};
	    },
	    [&](tickMsg) -> tea::Cmd {
		    m = model(m - 1);

		    if (m <= 0)
		    {
			    return tea::Quit;
		    }

		    return tick;
	    }
	);
}

auto View(model m) -> std::string
{
	return std::format(
	    "Hi. This program will exit in {} seconds.\n\n"
	    "To quit sooner press ctrl-c, or press ctrl-z to suspend...\n",
	    std::to_underlying(m)
	);
}

}

auto main() -> int
{
	try
	{
		auto logFile = utils::Getenv("BUBBLETEA_LOG").transform([](auto logfilePath) -> go::File {
			return *tea::LogToFile(logfilePath, "simple").transform_error(utils::ThrowGoError);
		});

		auto mod = model(5);
		utils::FreeStandingModelWrapper wrapper(mod);

		tea::NewProgram(wrapper).Run().transform_error(utils::ThrowGoError).value();
	}
	catch (const std::exception& e)
	{
		std::print("Fatal: {}\n", e.what());
		return 1;
	}
}
