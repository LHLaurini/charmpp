module;

#include "libcharm++go.h"
#include <concepts>
#include <stdexcept>
#include <string>

export module charm:go;

import :go.detail;

export namespace bubbletea
{

struct ErrProgramKilled : std::runtime_error
{
	using std::runtime_error::runtime_error;
};

struct ErrInterrupted : std::runtime_error
{
	using std::runtime_error::runtime_error;
};

}

export namespace go
{

// We keep the same name from Go
// NOLINTNEXTLINE(readability-identifier-naming)
class error : GoObject
{
  public:
	using GoObject::GoObject;

	[[nodiscard]] auto Error() const
	{
		return GoObject(::Error(GetHandle())).ToString();
	}

	[[noreturn]] auto Throw() const
	{
		auto str = Error();
		switch (::IdentifyError(GetHandle()))
		{
		case ::ErrUnknown:
			throw std::runtime_error(str);
		case ::ErrProgramKilled:
			throw bubbletea::ErrProgramKilled(str);
		case ::ErrInterrupted:
			throw bubbletea::ErrInterrupted(str);
		}
	}
};

class Stringer : go::GoObject
{
  public:
	[[nodiscard]] auto String() const
	{
		return go::GoObject(::String(GetHandle())).ToString();
	}

  private:
	using go::GoObject::GoObject;
};

template <typename T>
concept StringerLike = requires(const T& obj) {
	{ obj.String() } -> std::same_as<std::string>;
};

class File : go::GoObject
{
  public:
	File(const File&) = delete;
	File(File&&) = default;
	auto operator=(const File&) = delete;
	auto operator=(File&&) -> File& = default;

	~File() override
	{
		if (auto handle = GetHandle(); handle)
		{
			::FileClose(handle);
		}
	}

  private:
	using go::GoObject::GoObject;
};

}
