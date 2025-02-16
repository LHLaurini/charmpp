// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/set-window-title/main.go

#include <print>

import charm;

namespace tea = bubbletea;

struct model : tea::ModelBase
{
	auto Init() -> tea::Cmd override
	{
		return tea::SetWindowTitle("Bubble Tea Example");
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(msg, [&](const tea::KeyMsg& /*keyMsg*/) -> tea::Cmd {
			return tea::Quit;
		});
	}

	auto View() -> std::string override
	{
		return "\nPress any key to quit.";
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
		std::println("Uh oh: {}", e.what());
		return 1;
	}
}
