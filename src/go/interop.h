#pragma once

//NOLINTBEGIN

#include <stdbool.h>
#include <stdint.h>

#if __cplusplus
extern "C"
{
#endif

typedef enum
{
	MsgTypeUnknown,
	MsgTypeUser,
	MsgTypeKey,
} MsgType;

void toCppString(_GoString_ str, void* stringPtr);
uintptr_t callInit(void* modelPtr);
uintptr_t callUpdate(void* modelPtr, MsgType msgType, uintptr_t msgValue);
uintptr_t callView(void* modelPtr);
uintptr_t callAndDestroyCmd(uintptr_t cmdID);
uintptr_t getMsgIfGoObject(uintptr_t msgID);
const char* stringData(uintptr_t stringID);
int stringSize(uintptr_t stringID);
void destroyMsg(uintptr_t msgID);
void destroyString(uintptr_t stringID);

#if __cplusplus
}
#endif

//NOLINTEND