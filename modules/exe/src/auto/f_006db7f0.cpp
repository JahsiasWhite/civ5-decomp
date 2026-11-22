#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006db7f0]
void ShouldNotHappenFromLua(lua_State* L, int idx)
{
    luaL_error(L, "Should not happen");
}
