module;

#include "libcharm++go.h"
#include <any>
#include <expected>
#include <functional>
#include <string>
#include <variant>

export module charm:bubbletea.tea;

import :bubbletea.key;
import :go;

namespace bubbletea
{

export class UnknownMsg
{
};

export class QuitMsg
{
};

export class SuspendMsg
{
};

export using Msg = std::variant<UnknownMsg, KeyMsg, QuitMsg, SuspendMsg, std::any>;
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

// FIXME: Add opts ...ProgramOption
export auto NewProgram(ModelBase& model) -> Program
{
	return Program{ ::NewProgram(&model) };
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
