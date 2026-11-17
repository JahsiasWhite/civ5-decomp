// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_pushnumber callers)
// Pushes the int the second argument points at onto the Lua stack as a number.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006f59a0]
void PushIntAsNumberToLua(lua_State* L, const int* value)
{
    lua_pushnumber(L, *value);
}
