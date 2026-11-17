// TechAcquired event arguments can't be read back from Lua: raises a Lua error.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x00669650]
void TechAcquiredFromLua(lua_State* L, int idx)
{
    luaL_error(L, "FromLua called on TechAcquired - this shouldn't happen.");
}
