#include "LuaApi.h"

// src: EXE [0x00597b50]
int l_ExposedTypesToString_00597b50(lua_State* L);

// src: GUESS (confidence: high) [0x006715c0]
void InitExposedTypes_006715c0(lua_State* L)
{
    lua_getfield(L, LUA_GLOBALSINDEX, "ExposedTypes");
    if (lua_type(L, -1) != LUA_TTABLE)
    {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, LUA_GLOBALSINDEX, "ExposedTypes");
        lua_createtable(L, 0, 0);
        lua_pushcclosure(L, l_ExposedTypesToString_00597b50, 0);
        lua_setfield(L, -2, "__tostring");
        lua_rawseti(L, -2, 1);
    }
}
