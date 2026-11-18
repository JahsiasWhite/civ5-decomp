#include "LuaApi.h"

// src: EXE [0x0078e9c0]
int l_NewIndex_0078e9c0(lua_State* L);

// src: GUESS (confidence: high) [0x0049b410]
void WrapReadOnlyTable_0049b410(lua_State* L)
{
    lua_createtable(L, 0, 0);
    lua_createtable(L, 0, 0);
    lua_pushvalue(L, -3);
    lua_setfield(L, -2, "__index\0\0\0");
    lua_pushboolean(L, 0);
    lua_setfield(L, -2, "__metatable\0");
    lua_pushcclosure(L, l_NewIndex_0078e9c0, 0);
    lua_setfield(L, -2, "__newindex\0");
    lua_setmetatable(L, -2);
    lua_remove(L, -2);
}
