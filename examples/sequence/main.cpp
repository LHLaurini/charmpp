// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/sequence/main.go

#include <print>

import charm;

namespace tea = bubbletea;

struct model : tea::ModelBase
{
	auto Init() -> tea::Cmd override
	{
		return tea::Sequence(
		    tea::Batch(tea::Println("A"), tea::Println("B"), tea::Println("C")), //
		    tea::Println("Z"), tea::Quit
		);
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(msg, [&](const tea::KeyMsg& /*keyMsg*/) -> tea::Cmd {
			return tea::Quit;
		});
	}

	auto View() -> std::string override
	{
		return "";
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
