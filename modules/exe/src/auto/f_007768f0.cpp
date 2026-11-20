#include "LuaApi.h"

// src: GUESS (confidence: high) [0x007768f0]
int l_Where_007768f0(lua_State* L)
{
    luaL_where(L, luaL_optinteger(L, 1, 0));
    return 1;
}
