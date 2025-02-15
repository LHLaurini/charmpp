module;

#include <string>
#include <utility>

export module charm:bubbletea.key;

import :go;

export namespace bubbletea
{

enum class KeyType : int
{
	KeyF20 = -53,
	KeyF19,
	KeyF18,
	KeyF17,
	KeyF16,
	KeyF15,
	KeyF14,
	KeyF13,
	KeyF12,
	KeyF11,
	KeyF10,
	KeyF9,
	KeyF8,
	KeyF7,
	KeyF6,
	KeyF5,
	KeyF4,
	KeyF3,
	KeyF2,
	KeyF1,
	KeyCtrlShiftEnd,
	KeyCtrlShiftHome,
	KeyCtrlShiftRight,
	KeyCtrlShiftLeft,
	KeyCtrlShiftDown,
	KeyCtrlShiftUp,
	KeyShiftEnd,
	KeyShiftHome,
	KeyShiftLeft,
	KeyShiftRight,
	KeyShiftDown,
	KeyShiftUp,
	KeyCtrlEnd,
	KeyCtrlHome,
	KeyCtrlLeft,
	KeyCtrlRight,
	KeyCtrlDown,
	KeyCtrlUp,
	KeySpace,
	KeyInsert,
	KeyDelete,
	KeyCtrlPgDown,
	KeyCtrlPgUp,
	KeyPgDown,
	KeyPgUp,
	KeyEnd,
	KeyHome,
	KeyShiftTab,
	KeyLeft,
	KeyRight,
	KeyDown,
	KeyUp,
	KeyRunes,
	KeyCtrlAt, // 0
	KeyCtrlA,
	KeyCtrlB,
	KeyCtrlC,
	KeyCtrlD,
	KeyCtrlE,
	KeyCtrlF,
	KeyCtrlG,
	KeyCtrlH,
	KeyCtrlI,
	KeyCtrlJ,
	KeyCtrlK,
	KeyCtrlL,
	KeyCtrlM,
	KeyCtrlN,
	KeyCtrlO,
	KeyCtrlP,
	KeyCtrlQ,
	KeyCtrlR,
	KeyCtrlS,
	KeyCtrlT,
	KeyCtrlU,
	KeyCtrlV,
	KeyCtrlW,
	KeyCtrlX,
	KeyCtrlY,
	KeyCtrlZ,
	KeyCtrlOpenBracket,
	KeyCtrlBackslash,
	KeyCtrlCloseBracket,
	KeyCtrlCaret,
	KeyCtrlUnderscore, // 31
};

using enum KeyType;

// We separate the sequential values from these
constexpr auto KeyNull = KeyCtrlAt;
constexpr auto KeyBreak = KeyCtrlC;
constexpr auto KeyTab = KeyCtrlI;
constexpr auto KeyEnter = KeyCtrlM;
constexpr auto KeyEsc = KeyCtrlOpenBracket;
constexpr auto KeyEscape = KeyEsc;
constexpr auto KeyBackspace = static_cast<KeyType>(127);
constexpr auto KeyCtrlQuestionMark = KeyBackspace;

// NOLINTNEXTLINE(*-magic-numbers)
static_assert(std::to_underlying(KeyCtrlUnderscore) == 31);

struct Key
{
	KeyType Type;
	std::u32string Runes;
	bool Alt;
	bool Paste;

	[[nodiscard]] auto String() const -> std::string;
};

using KeyMsg = Key;

}
