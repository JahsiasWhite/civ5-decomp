// Pushes the int that the second argument points at onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x00459da0]
void PushIntToLua(lua_State* L, const int* value)
{
    lua_pushinteger(L, *value);
}
