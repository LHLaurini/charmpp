// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/mouse/main.go

#include <exception>
#include <print>

import charm;

namespace tea = bubbletea;

struct model : tea::ModelBase
{
	// The original example has a mouseEvent field, but doesn't use it

	auto Init() -> tea::Cmd override
	{
		return {};
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(
		    msg,
		    [](const tea::KeyMsg& keyMsg) -> tea::Cmd {
			    if (auto str = keyMsg.String(); str == "ctrl+c" || str == "q" || str == "esc")
			    {
				    return tea::Quit;
			    }
			    return {};
		    },
		    [](const tea::MouseMsg& mouseMsg) -> tea::Cmd {
			    return tea::Print("(X: {}, Y: {}) {}", mouseMsg.X, mouseMsg.Y, mouseMsg);
		    }
		);

		return {};
	};

	auto View() -> std::string override
	{
		return "Do mouse stuff. When you're done press q to quit.\n";
	}
};

auto main() -> int
{
	try
	{
		model mod;

		tea::NewProgram(mod, tea::WithMouseAllMotion())
		    .Run()
		    .transform_error(utils::ThrowGoError)
		    .value();
	}
	catch (const std::exception& e)
	{
		std::print("Fatal: {}\n", e.what());
		return 1;
	}
}
