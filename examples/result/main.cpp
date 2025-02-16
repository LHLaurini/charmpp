// based on https://github.com/charmbracelet/bubbletea/blob/main/examples/result/main.go

#include <print>

import charm;

namespace tea = bubbletea;

constexpr std::array choices = { "Taro", "Coffee", "Lychee" };

struct model : tea::ModelBase
{
	int cursor = 0;
	std::string choice;

	auto Init() -> tea::Cmd override
	{
		return {};
	}

	auto Update(tea::Msg msg) -> tea::Cmd override
	{
		return utils::VisitMsg(msg, [&](const tea::KeyMsg& keyMsg) -> tea::Cmd {
			auto str = keyMsg.String();

			if (str == "ctrl+c" || str == "q" || str == "esc")
			{
				return tea::Quit;
			}

			if (str == "enter")
			{
				choice = choices.at(cursor);
				return tea::Quit;
			}

			if (str == "down" || str == "j")
			{
				cursor++;
				if (cursor >= std::size(choices))
				{
					cursor = 0;
				}
			}
			else if (str == "up" || str == "k")
			{
				cursor--;
				if (cursor < 0)
				{
					cursor = std::size(choices) - 1;
				}
			}

			return {};
		});
	}

	auto View() -> std::string override
	{
		std::string s;

		s += "What kind of Bubble Tea would you like to order?\n\n";

		for (auto i = 0U; i < std::size(choices); i++)
		{
			if (cursor == i)
			{
				s += "(•) ";
			}
			else
			{
				s += "( ) ";
			}
			s += choices.at(i);
			s += "\n";
		}
		s += "\n(press q to quit)\n";
		return s;
	}
};

auto main() -> int
{
	try
	{
		model mod;
		tea::NewProgram(mod).Run().transform_error(utils::ThrowGoError).value();

		if (mod.choice != "")
		{
			std::print("\n---\nYou chose {}!\n", mod.choice);
		}
	}
	catch (const std::exception& e)
	{
		std::println("Oh no: {}", e.what());
		return 1;
	}
}
