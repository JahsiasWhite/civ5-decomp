#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00758840]
int l_AppendUpvalue_00758840(lua_State* L)
{
    lua_pushvalue(L, -1);
    lua_rawseti(L, lua_upvalueindex(1), lua_objlen(L, lua_upvalueindex(1)) + 1);
    return 1;
}
