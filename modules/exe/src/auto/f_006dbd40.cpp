#include "LuaApi.h"
#include <string.h>

// src: GUESS (confidence: high) [0x006dbd40]
void ReadString256_006dbd40(lua_State* L, char* dst)
{
    strncpy(dst, lua_tolstring(L, 1, 0), 0x100);
}
