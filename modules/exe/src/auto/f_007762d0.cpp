#include "LuaApi.h"

// src: LIB [0x00889690]
extern "C" void lua_settable(lua_State* L, int idx);

// src: GUESS (confidence: high) [0x007762d0]
int ClearLuaUpvalueKey_007762d0(lua_State* L)
{
    lua_pushvalue(L, -10003);
    lua_pushvalue(L, 1);
    lua_pushnil(L);
    lua_settable(L, -3);
    return 0;
}
