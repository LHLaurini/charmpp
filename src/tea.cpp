module;

#include "libcharm++go.h"
#include <any>
#include <array>
#include <cstdint>
#include <expected>
#include <functional>
#include <string>
#include <variant>

export module charm:bubbletea.tea;

import :bubbletea.focus;
import :bubbletea.key;
import :bubbletea.mouse;
import :bubbletea.options;
import :bubbletea.standard_renderer.detail;
import :go;

export namespace bubbletea
{

class UnknownMsg
{
};

struct InternalMsg
{
	uintptr_t Handle;
};

class InterruptMsg
{
};

class QuitMsg
{
};

class ResumeMsg
{
};

class SuspendMsg
{
};

using Msg = std::variant<
    UnknownMsg, InternalMsg, BlurMsg, FocusMsg, InterruptMsg, KeyMsg, MouseEvent, QuitMsg,
    ResumeMsg, SuspendMsg, WindowSizeMsg, std::any>;
using Cmd = std::function<Msg()>;

class ModelBase
{
  public:
	ModelBase() = default;
	ModelBase(const ModelBase&) = default;
	ModelBase(ModelBase&&) = default;
	auto operator=(const ModelBase&) -> ModelBase& = default;
	auto operator=(ModelBase&&) -> ModelBase& = default;
	virtual ~ModelBase() = default;

	virtual auto Init() -> Cmd = 0;
	virtual auto Update(Msg msg) -> Cmd = 0;
	virtual auto View() -> std::string = 0;
};

class Program : go::GoObject
{
	friend auto NewProgram(ModelBase& model) -> Program;

  public:
	auto Run() -> std::expected<void, go::error>
	{
		if (auto handle = ::ProgramRun(GetHandle()); handle != 0)
		{
			return std::unexpected<go::error>(handle);
		}
		return {};
	}

  private:
	using go::GoObject::GoObject;
};

auto NewProgram(ModelBase& model, std::same_as<ProgramOption> auto... opts) -> Program
{
	std::array<std::uintptr_t, sizeof...(opts)> optionArray{ opts.GetHandle()... };
	return Program{ ::NewProgram(&model, optionArray.data(), optionArray.size()) };
}

auto Interrupt() -> InterruptMsg
{
	return {};
}

auto Quit() -> QuitMsg
{
	return {};
}

auto Suspend() -> SuspendMsg
{
	return {};
}

}
