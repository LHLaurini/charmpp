module;

#include "libcharm++go.h"
#include <any>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <print>
#include <ranges>
#include <span>
#include <string>
#include <unordered_map>
#include <utility>
#include <variant>

export module charm:interop.detail;

import :bubbletea.focus;
import :bubbletea.tea;
import :go;

namespace tea = bubbletea;

// Clang 19.1.7 fails to build without this -- possible compiler bug
namespace go
{
class GoObject;
}

template <typename T>
struct StoreAccessor;

// Ideally we'd use lists, but we don't have a way to send Go the iterators. Instead, we use maps
// with monotonic indices.
template <typename T>
class Store
{
	friend StoreAccessor<T>;

  public:
	Store(const Store&) = delete;
	Store(Store&&) = delete;
	auto operator=(const Store&) = delete;
	auto operator=(Store&&) = delete;

	auto Stow(T obj)
	{
		storage.emplace(nextID, std::move(obj));
		return nextID++;
	}

	auto Get(std::uintptr_t id) -> auto&
	{
		return storage.at(id);
	}

	auto Detach(std::uintptr_t id)
	{
		auto result = std::move(Get(id));
		Destroy(id);
		return result;
	}

	void Destroy(std::uintptr_t id)
	{
		storage.erase(id);
	}

	~Store()
	{
#ifndef NDEBUG
		if (!storage.empty())
		{
			try
			{
				std::print(stderr, "Note: program exited with {} live objects.\n", storage.size());
			}
			catch (...)
			{
				return;
			}
		}
#endif
	}

  private:
	Store() = default;

	std::unordered_map<std::uintptr_t, T> storage;
	std::uintptr_t nextID = 1;
};

template <typename T>
struct StoreAccessor
{
	auto operator()() const -> auto&
	{
		static Store<T> storage;
		return storage;
	}
};

template <typename T>
static constexpr StoreAccessor<T> GetStore;

[[nodiscard]] auto ToCppKey(const ::GoKey& key) -> tea::Key
{
	return {
		.Type = static_cast<tea::KeyType>(key.Type),
		.Runes = std::ranges::to<std::u32string>(std::span(key.Runes, key.NumRunes)),
		.Alt = key.Alt,
		.Paste = key.Paste,
	};
}

auto FromCppKey(const tea::Key& key) -> ::CppKey
{
	return {
		.Type = std::to_underlying(key.Type),
		.Runes = key.Runes.data(),
		.NumRunes = static_cast<unsigned int>(key.Runes.size()),
		.Alt = key.Alt,
		.Paste = key.Paste,
	};
}

[[nodiscard]] auto ToCppMouseEvent(const ::InterMouseEvent& mouseEvent) -> tea::MouseEvent
{
	return {
		.X = mouseEvent.X,
		.Y = mouseEvent.Y,
		.Shift = mouseEvent.Shift,
		.Alt = mouseEvent.Alt,
		.Ctrl = mouseEvent.Ctrl,
		.Action = static_cast<tea::MouseAction>(mouseEvent.Action),
		.Button = static_cast<tea::MouseButton>(mouseEvent.Button),
	};
}

auto FromCppMouseEvent(const tea::MouseEvent& mouseEvent) -> ::InterMouseEvent
{
	return {
		.X = mouseEvent.X,
		.Y = mouseEvent.Y,
		.Shift = mouseEvent.Shift,
		.Alt = mouseEvent.Alt,
		.Ctrl = mouseEvent.Ctrl,
		.Action = mouseEvent.Action,
		.Button = mouseEvent.Button,
	};
}

struct MsgToGo
{
	auto operator()(tea::UnknownMsg /*msg*/) const -> MsgTypeAndMsg
	{
		// FIXME: throw exception here
		std::terminate();
	}

	auto operator()(tea::InternalMsg msg) const -> MsgTypeAndMsg
	{
		return { MsgTypeInternal, msg.Handle };
	}

	auto operator()(tea::BlurMsg /*msg*/) const -> MsgTypeAndMsg
	{
		return { MsgTypeBlur, 0 };
	}

	auto operator()(tea::FocusMsg /*msg*/) const -> MsgTypeAndMsg
	{
		return { MsgTypeFocus, 0 };
	}

	auto operator()(tea::InterruptMsg /*msg*/) const -> MsgTypeAndMsg
	{
		return { MsgTypeInterrupt, 0 };
	}

	auto operator()(const tea::KeyMsg& msg) const -> MsgTypeAndMsg
	{
		return { MsgTypeKey, ::ToGoKey(FromCppKey(msg)) };
	}

	auto operator()(const tea::MouseMsg& msg) const -> MsgTypeAndMsg
	{
		return { MsgTypeMouse, ::ToGoMouseEvent(FromCppMouseEvent(msg)) };
	}

	auto operator()(tea::QuitMsg /*msg*/) const -> MsgTypeAndMsg
	{
		return { MsgTypeQuit, 0 };
	}

	auto operator()(tea::ResumeMsg /*msg*/) const -> MsgTypeAndMsg
	{
		return { MsgTypeResume, 0 };
	}

	auto operator()(tea::SuspendMsg /*msg*/) const -> MsgTypeAndMsg
	{
		return { MsgTypeSuspend, 0 };
	}

	auto operator()(std::any msg) const -> MsgTypeAndMsg
	{
		return { MsgTypeUser, GetStore<std::any>().Stow(std::move(msg)) };
	}
};

extern "C"
{

auto fromCppKey(uintptr_t id) -> ::CppKey
{
	return ::FromCppKey(GetStore<tea::Key>().Get(id));
}

auto toCppKey(::GoKey key) -> uintptr_t
{
	return GetStore<tea::Key>().Stow(::ToCppKey(key));
}

auto toCppMouseEvent(InterMouseEvent mouseEvent) -> uintptr_t
{
	return GetStore<tea::MouseEvent>().Stow(::ToCppMouseEvent(mouseEvent));
}

void toCppString(GoString str, void* stringPtr)
{
	auto& stringOut = *static_cast<std::string*>(stringPtr);
	stringOut.assign(str.p, static_cast<std::size_t>(str.n));
}

auto callInit(void* modelPtr) -> std::uintptr_t
{
	auto&& cmd = static_cast<tea::ModelBase*>(modelPtr)->Init();
	if (cmd)
	{
		return GetStore<tea::Cmd>().Stow(std::move(cmd));
	}
	return 0;
}

auto callUpdate(void* modelPtr, MsgType msgType, std::uintptr_t msgValue) -> std::uintptr_t
{
	auto makeMsg = [&] -> tea::Msg {
		switch (msgType)
		{
		case MsgType::MsgTypeUnknown:
			return tea::UnknownMsg();

		case MsgType::MsgTypeInternal:
			// We shouldn't receive these
			// FIXME: throw exception here
			std::terminate();

		case MsgType::MsgTypeBlur:
			return tea::BlurMsg();

		case MsgType::MsgTypeFocus:
			return tea::FocusMsg();

		case MsgType::MsgTypeInterrupt:
			return tea::InterruptMsg();

		case MsgType::MsgTypeKey:
			return GetStore<tea::Key>().Detach(msgValue);

		case MsgType::MsgTypeMouse:
			return GetStore<tea::MouseEvent>().Detach(msgValue);

		case MsgType::MsgTypeQuit:
			return tea::QuitMsg();

		case MsgType::MsgTypeResume:
			return tea::ResumeMsg();

		case MsgType::MsgTypeSuspend:
			return tea::SuspendMsg();

		case MsgType::MsgTypeUser:
			return GetStore<std::any>().Detach(msgValue);
		}
	};

	auto&& cmd = static_cast<tea::ModelBase*>(modelPtr)->Update(makeMsg());
	if (cmd)
	{
		return GetStore<tea::Cmd>().Stow(std::move(cmd));
	}
	return 0;
}

auto callView(void* modelPtr) -> std::uintptr_t
{
	return GetStore<std::string>().Stow(static_cast<tea::ModelBase*>(modelPtr)->View());
}

auto callAndDestroyCmd(std::uintptr_t cmdID) -> MsgTypeAndMsg
{
	return std::visit(MsgToGo{}, GetStore<tea::Cmd>().Detach(cmdID)());
}

auto stringData(std::uintptr_t stringID) -> const char*
{
	return GetStore<std::string>().Get(stringID).data();
}

auto stringSize(std::uintptr_t stringID) -> int
{
	return static_cast<int>(GetStore<std::string>().Get(stringID).size());
}

void destroyMsg(std::uintptr_t msgID)
{
	GetStore<tea::Msg>().Destroy(msgID);
}

void destroyString(std::uintptr_t stringID)
{
	GetStore<std::string>().Destroy(stringID);
}
}
