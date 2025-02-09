module;

#include <string>

export module charm:bubbletea.mouse;

import :go;

export namespace bubbletea
{

enum MouseAction
{
	MouseActionPress,
	MouseActionRelease,
	MouseActionMotion,
};

enum MouseButton
{
	MouseButtonNone,
	MouseButtonLeft,
	MouseButtonMiddle,
	MouseButtonRight,
	MouseButtonWheelUp,
	MouseButtonWheelDown,
	MouseButtonWheelLeft,
	MouseButtonWheelRight,
	MouseButtonBackward,
	MouseButtonForward,
	MouseButton10,
	MouseButton11,
};

struct MouseEvent
{
	int X;
	int Y;
	bool Shift;
	bool Alt;
	bool Ctrl;
	MouseAction Action;
	MouseButton Button;

	[[nodiscard]] auto IsWheel() const -> bool;
	[[nodiscard]] auto String() const -> std::string;
};

using MouseMsg = MouseEvent;

}
