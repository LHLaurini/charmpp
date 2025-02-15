// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/suspend/main.go

#include <print>

import charm;

namespace tea = bubbletea;

struct model : tea::ModelBase
{
	bool quitting;
	bool suspending;

	explicit model(bool quitting = false, bool suspending = false)
	    : quitting(quitting)
	    , suspending(suspending)
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
		    [&](const tea::ResumeMsg& /*resumeMsg*/) -> tea::Cmd {
			    suspending = false;
			    return {};
		    },
		    [&](const tea::KeyMsg& keyMsg) -> tea::Cmd {
			    auto keyStr = keyMsg.String();
			    if (keyStr == "q" || keyStr == "esc")
			    {
				    quitting = true;
				    return tea::Quit;
			    }
			    if (keyStr == "ctrl+c")
			    {
				    quitting = true;
				    return tea::Interrupt;
			    }
			    if (keyStr == "ctrl+z")
			    {
				    suspending = true;
				    return tea::Suspend;
			    }
			    return {};
		    }
		);
	}

	auto View() -> std::string override
	{
		if (suspending || quitting)
		{
			return "";
		}

		return "\nPress ctrl-z to suspend, ctrl+c to interrupt, q, or esc to exit\n";
	}
};

auto main() -> int
{
	try
	{
		model mod;
		tea::NewProgram(mod).Run().transform_error(utils::ThrowGoError).value();
	}
	catch (const tea::ErrInterrupted&)
	{
		return 130;
	}
	catch (const std::exception& e)
	{
		std::println("Fatal: {}", e.what());
		return 1;
	}
}
