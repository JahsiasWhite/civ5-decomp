// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: high) [0x0044a3e0]

#include "LuaApi.h"

void SetupTable_0044a3e0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, "__newindex");
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, "__metatable");
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
