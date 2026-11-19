// Reads a Lua argument as a boolean, or returns the default when it's
// missing or nil.

#include "LuaApi.h"

extern "C" int lua_type(lua_State* L, int idx);

// src: GUESS (confidence: low) [0x00596c00]
bool ToBoolOr_00596c00(lua_State* L, int idx, bool defaultValue)
{
    if (lua_type(L, idx) <= 0)
        return defaultValue;
    return lua_toboolean(L, idx) ? true : false;
}
