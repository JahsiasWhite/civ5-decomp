#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00904240]
void InitCodeBuddy_00904240(lua_State* L)
{
    lua_checkstack(L, 2);
    lua_getfield(L, LUA_GLOBALSINDEX, "CodeBuddy");
    if (lua_type(L, -1) != LUA_TTABLE)
    {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, LUA_GLOBALSINDEX, "CodeBuddy\0");
    }
}
