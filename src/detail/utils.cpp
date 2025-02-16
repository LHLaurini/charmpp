module;

#include <concepts>
#include <ranges>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

export module charm:utils.detail;

import :bubbletea.tea;

namespace tea = bubbletea;

namespace utils
{

auto ConvertArgs()
{
	return std::tuple{};
}

template <typename T>
concept ContiguousSizedRange =
    std::ranges::contiguous_range<const T> && std::ranges::sized_range<const T>;

template <ContiguousSizedRange R>
auto ConvertArg(R& range)
{
	// cgo doesn't support const, so we strip it away
	// NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
	return std::tuple{ const_cast<std::ranges::range_value_t<R>*>(range.data()), range.size() };
}

auto ConvertArgs(auto first, auto... others)
{
	return std::tuple_cat(ConvertArg(first), ConvertArgs(others...));
}

/// Call \p func after converting \p args.
/// This function performs the following conversions:
/// - String-like objects (std::string, std::string_view, std::vector<char>, std::span<char, ...>,
///   std::array<char, ...>, char[...]) become `char*`, `int`
template <typename Ret, typename... Params>
auto CgoCall(Ret (*func)(Params...), auto... args)
{
	return std::apply(func, ConvertArgs(args...));
}

template <typename Type>
struct LambdaParamImpl
{
	static constexpr auto Valid = false;
};

template <typename Ret, typename Lambda, typename Param>
requires(std::same_as<Ret, tea::Cmd> || std::same_as<Ret, void>)
struct LambdaParamImpl<Ret (Lambda::*)(Param) const>
{
	static constexpr auto Valid = true;
	using ReturnType = Ret;
	using ParameterType = Param;
};

template <typename Type>
using LambdaParamHelper = LambdaParamImpl<decltype(&Type::operator())>;

template <typename Type>
using LambdaRet = typename LambdaParamHelper<Type>::ReturnType;

template <typename Type>
using LambdaParam = typename LambdaParamHelper<Type>::ParameterType;

template <typename Type, typename Variant>
struct IsInVariantImpl : std::false_type
{
};

template <typename Type, typename... VariantTypes>
struct IsInVariantImpl<Type, std::variant<VariantTypes...>>
    : std::bool_constant<(std::same_as<Type, VariantTypes> || ...)>
{
};

template <typename Type, typename Variant>
concept IsInVariant = IsInVariantImpl<Type, Variant>::value;

struct FreeStandingModelBase
{
	FreeStandingModelBase() = default;
	FreeStandingModelBase(const FreeStandingModelBase&) = default;
	FreeStandingModelBase(FreeStandingModelBase&&) = default;
	auto operator=(const FreeStandingModelBase&) -> FreeStandingModelBase& = default;
	auto operator=(FreeStandingModelBase&&) -> FreeStandingModelBase& = default;
	virtual ~FreeStandingModelBase() = default;

	virtual auto InitImpl() -> bubbletea::Cmd = 0;
	virtual auto UpdateImpl(bubbletea::Msg msg) -> bubbletea::Cmd = 0;
	virtual auto ViewImpl() -> std::string = 0;
};

template <typename T>
class FreeStandingModelImpl : public FreeStandingModelBase
{
  public:
	explicit FreeStandingModelImpl(T& value) : value(&value)
	{
	}

	auto InitImpl() -> bubbletea::Cmd final
	{
		return Init(*value);
	}

	auto UpdateImpl(bubbletea::Msg msg) -> bubbletea::Cmd final
	{
		return Update(*value, std::move(msg));
	}

	auto ViewImpl() -> std::string final
	{
		return View(*value);
	}

  private:
	T* value;
};

}
