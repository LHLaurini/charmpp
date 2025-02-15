module;

#include <any>
#include <concepts>
#include <cstdlib>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <variant>

export module charm:utils;

import :bubbletea.tea;
import :utils.detail;

namespace tea = bubbletea;

export namespace utils
{

/// Requirements:
/// - Must be a non-mutable lambda;
/// - Must be non-overloaded;
/// - Must return either void or Cmd.
template <typename Type>
concept MsgVisitor = LambdaParamHelper<Type>::Valid;

template <MsgVisitor First, MsgVisitor... Others>
auto VisitMsg(tea::Msg& msg, First firstVisitor, Others... otherVisitors) -> tea::Cmd
{
	using Ret = LambdaRet<First>;
	using Param = LambdaParam<First>;
	using ParamValue = std::remove_cvref_t<Param>;

	auto* any = std::get_if<std::any>(&msg);

	if (any && any->type() == typeid(ParamValue))
	{
		if constexpr (std::same_as<Ret, tea::Cmd>)
		{
			return firstVisitor(std::any_cast<Param>(*any));
		}
		else
		{
			firstVisitor(std::any_cast<Param>(*any));
			return nullptr;
		}
	}

	if constexpr (IsInVariant<ParamValue, tea::Msg>)
	{
		if (std::holds_alternative<ParamValue>(msg))
		{
			if constexpr (std::same_as<Ret, tea::Cmd>)
			{
				return firstVisitor(std::get<ParamValue>(msg));
			}
			else
			{
				firstVisitor(std::get<ParamValue>(msg));
				return nullptr;
			}
		}
	}

	if constexpr (sizeof...(Others) > 0)
	{
		return VisitMsg(msg, std::move(otherVisitors)...);
	}

	return nullptr;
}

[[noreturn]] auto ThrowGoError(const go::error& err) -> go::error
{
	err.Throw();
}

[[nodiscard]] auto Getenv(const std::string& name) -> std::optional<std::string_view>
{
	auto* value = std::getenv(name.c_str());

	if (value == nullptr)
	{
		return std::nullopt;
	}

	return value;
}

template <typename T>
concept FreeStandingModel = requires(T& model, tea::Msg msg) {
	{ Init(model) } -> std::same_as<tea::Cmd>;
	{ Update(model, std::move(msg)) } -> std::same_as<tea::Cmd>;
	{ View(model) } -> std::same_as<std::string>;
};

template <FreeStandingModel T>
class FreeStandingModelWrapper : public bubbletea::ModelBase
{
  public:
	explicit FreeStandingModelWrapper(T& value) : impl(value)
	{
	}

	auto Init() -> bubbletea::Cmd final
	{
		return impl.InitImpl();
	}

	auto Update(bubbletea::Msg msg) -> bubbletea::Cmd final
	{
		return impl.UpdateImpl(std::move(msg));
	}

	auto View() -> std::string final
	{
		return impl.ViewImpl();
	}

  private:
	FreeStandingModelImpl<T> impl;
};

}
