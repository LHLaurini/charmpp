#pragma once

//NOLINTBEGIN

#include <stdbool.h>
#include <stdint.h>
#include <uchar.h>

#if __cplusplus
extern "C"
{
#endif

typedef int32_t rune;

typedef enum
{
	MsgTypeUnknown,
	MsgTypeUser,
	MsgTypeKey,
	MsgTypeQuit,
	MsgTypeSuspend,
} MsgType;

typedef struct
{
	int Type;
	// We'd ideally use char32_t, but that type could be larger than 32-bits (and we need it to
	// match Go)
	const rune* Runes;
	unsigned NumRunes; // Extra
	bool Alt;
	bool Paste;
} GoKey;

typedef struct
{
	int Type;
	const char32_t* Runes;
	unsigned NumRunes; // Extra
	bool Alt;
	bool Paste;
} CppKey;

typedef struct
{
	MsgType Type;
	uintptr_t Msg;
} MsgTypeAndMsg;

CppKey fromCppKey(uintptr_t id);
uintptr_t toCppKey(GoKey key);
void toCppString(_GoString_ str, void* stringPtr);
uintptr_t callInit(void* modelPtr);
uintptr_t callUpdate(void* modelPtr, MsgType msgType, uintptr_t msgValue);
uintptr_t callView(void* modelPtr);
MsgTypeAndMsg callAndDestroyCmd(uintptr_t cmdID);
const char* stringData(uintptr_t stringID);
int stringSize(uintptr_t stringID);
void destroyMsg(uintptr_t msgID);
void destroyString(uintptr_t stringID);

#if __cplusplus
}
#endif

//NOLINTEND