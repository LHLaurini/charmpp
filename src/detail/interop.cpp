module;

#include "libcharm++go.h"
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <print>
#include <string>
#include <unordered_map>
#include <utility>
#include <variant>

export module charm:interop;

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

// tea::Cmd
// tea::Msg
// std::string

extern "C"
{

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
			return tea::UnknownMsg(msgValue);

		case MsgType::MsgTypeKey:
			return tea::KeyMsg(msgValue);

		case MsgType::MsgTypeUser:
			return GetStore<tea::Msg>().Detach(msgValue);
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

auto callAndDestroyCmd(std::uintptr_t cmdID) -> std::uintptr_t
{
	auto& cmd = GetStore<tea::Cmd>().Get(cmdID);
	auto msg = GetStore<tea::Msg>().Stow(cmd());
	GetStore<tea::Cmd>().Destroy(cmdID);
	return msg;
}

auto getMsgIfGoObject(std::uintptr_t msgID) -> std::uintptr_t
{
	return std::visit(
	    []<typename T>(const T& msg) -> std::uintptr_t {
		    if constexpr (std::derived_from<T, go::GoObject>)
		    {
			    return msg.GetHandle();
		    }
		    else
		    {
			    return 0;
		    }
	    },
	    GetStore<tea::Msg>().Get(msgID)
	);
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
