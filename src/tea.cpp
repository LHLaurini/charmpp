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

namespace bubbletea
{

export class UnknownMsg
{
};

export struct InternalMsg
{
	uintptr_t Handle;
};

export class InterruptMsg
{
};

export class QuitMsg
{
};

export class ResumeMsg
{
};

export class SuspendMsg
{
};

export using Msg = std::variant<
    UnknownMsg, InternalMsg, BlurMsg, FocusMsg, InterruptMsg, KeyMsg, MouseEvent, QuitMsg,
    ResumeMsg, SuspendMsg, std::any>;
export using Cmd = std::function<Msg()>;

export class ModelBase
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

export class Program : go::GoObject
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

export auto NewProgram(ModelBase& model, std::same_as<ProgramOption> auto... opts) -> Program
{
	std::array<std::uintptr_t, sizeof...(opts)> optionArray{ opts.GetHandle()... };
	return Program{ ::NewProgram(&model, optionArray.data(), optionArray.size()) };
}

export auto Interrupt() -> InterruptMsg
{
	return {};
}

export auto Quit() -> QuitMsg
{
	return {};
}

export auto Suspend() -> SuspendMsg
{
	return {};
}

}
