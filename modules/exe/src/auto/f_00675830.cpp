#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00675830]
int l_CallUpvalue_00675830(lua_State* L)
{
    int (*fn)(lua_State*) = (int (*)(lua_State*))lua_touserdata(L, lua_upvalueindex(1));
    lua_tolstring(L, lua_upvalueindex(2), 0);
    return fn(L);
}
