module;

#include "libcharm++go.h"

export module charm:bubbletea.options;

import :go;

export namespace bubbletea
{

class ProgramOption : public go::GoObject
{
  private:
	using go::GoObject::GoObject;
};

auto WithMouseAllMotion()
{
	return ProgramOption(::WithMouseAllMotion());
}

}
