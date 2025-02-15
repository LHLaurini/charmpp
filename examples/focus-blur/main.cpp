// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/focus-blur/main.go

#include <print>

import charm;

namespace tea = bubbletea;

struct model : tea::ModelBase
{
	bool focused;
	bool reporting;

	model(bool focused, bool reporting) : focused(focused), reporting(reporting)
	{
	}

	auto Init() -> tea::Cmd override
	{
		return {};
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(
		    msg,
		    [&](const tea::FocusMsg& /*focusMsg*/) -> tea::Cmd {
			    focused = true;
			    return {};
		    },
		    [&](const tea::BlurMsg& /*blurMsg*/) -> tea::Cmd {
			    focused = false;
			    return {};
		    },
		    [&](const tea::KeyMsg& keyMsg) -> tea::Cmd {
			    auto keyStr = keyMsg.String();
			    if (keyStr == "t")
			    {
				    reporting = !reporting;
			    }
			    else if (keyStr == "ctrl+c" || keyStr == "q")
			    {
				    return tea::Quit;
			    }
			    return {};
		    }
		);
	}

	auto View() -> std::string override
	{
		std::string s = "Hi. Focus report is currently ";

		if (reporting)
		{
			s += "enabled";
		}
		else
		{
			s += "disabled";
		}
		s += ".\n\n";

		if (reporting)
		{
			if (focused)
			{
				s += "This program is currently focused!";
			}
			else
			{
				s += "This program is currently blurred!";
			}
		}
		return s + "\n\nTo quit sooner press ctrl-c, or t to toggle focus reporting...\n";
	}
};

auto main() -> int
{
	try
	{
		model mod{ true, true };
		tea::NewProgram(mod, tea::WithReportFocus())
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
