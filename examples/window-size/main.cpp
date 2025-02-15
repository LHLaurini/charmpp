// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/window-size/main.go

#include <print>

import charm;

namespace tea = bubbletea;

struct model : tea::ModelBase
{
	auto Init() -> tea::Cmd override
	{
		return {};
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(
		    msg,
		    [&](const tea::KeyMsg& keyMsg) -> tea::Cmd {
			    if (auto s = keyMsg.String(); s == "ctrl+c" || s == "q" || s == "esc")
			    {
				    return tea::Quit;
			    }
			    return tea::WindowSize();
		    },
		    [&](const tea::WindowSizeMsg& winSizeMsg) -> tea::Cmd {
			    return tea::Print("{}x{}", winSizeMsg.Width, winSizeMsg.Height);
		    }
		);
	}

	auto View() -> std::string override
	{
		return "When you're done press q to quit. Press any other key to query the window-size.\n";
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
		std::println("Fatal: {}", e.what());
		return 1;
	}
}
