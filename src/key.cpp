module;

#include "libcharm++go.h"
#include <cstdint>

export module charm:bubbletea.key;

import :go;

export namespace bubbletea
{

class Key : public go::Stringer
{
	friend auto callUpdate(void* modelPtr, MsgType msgType, std::uintptr_t msgValue);

  private:
	using go::Stringer::Stringer;
};

using KeyMsg = Key;

}
