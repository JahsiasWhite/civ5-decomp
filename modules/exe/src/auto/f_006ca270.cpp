// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_pushnumber callers)
// Pushes the float the second argument points at onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006ca270]
void PushFloatToLua(lua_State* L, const float* value)
{
    lua_pushnumber(L, *value);
}
