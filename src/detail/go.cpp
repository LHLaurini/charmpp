module;

#include "libcharm++go.h"
#include <cstdint>
#include <expected>
#include <string>

export module charm:go.detail;

namespace go
{

class GoObject
{
  public:
	using Handle = std::uintptr_t;

	explicit GoObject(Handle handle) : handle(handle)
	{
	}

	GoObject(const GoObject&) = delete;

	GoObject(GoObject&& other) noexcept : handle(other.handle)
	{
		other.handle = 0;
	}

	auto operator=(const GoObject&) = delete;

	auto operator=(GoObject&& other) noexcept -> auto&
	{
		Destroy();
		handle = other.Detach();
		return *this;
	}

	virtual ~GoObject()
	{
		Destroy();
	}

	[[nodiscard]] auto ToString() const
	{
		std::string string;
		::ToCppString(handle, &string);
		return string;
	}

	[[nodiscard]] auto GetHandle() const
	{
		return handle;
	}

  private:
	auto Detach() -> Handle
	{
		auto copy = handle;
		handle = 0;
		return copy;
	}

	void Destroy()
	{
		if (handle != 0)
		{
			::DeleteHandle(handle);
			handle = 0;
		}
	}

	Handle handle;
};

}
