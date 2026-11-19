// Lua-to-C conversion stub that must never run: raises a Lua error.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006a9030]
void RejectFromLua_006a9030(lua_State* L, int idx)
{
    luaL_error(L, "Don't call this");
}
