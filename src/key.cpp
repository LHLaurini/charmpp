module;
export module charm:bubbletea.key;

import :go;

export namespace bubbletea
{

class Key : public go::Stringer
{
  private:
	using go::Stringer::Stringer;
};

using KeyMsg = Key;

}
