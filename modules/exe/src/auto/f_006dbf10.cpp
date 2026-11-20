#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006dbf10]
void PushPair_006dbf10(lua_State* L, const int* p)
{
    lua_pushinteger(L, p[0]);
    lua_pushinteger(L, p[1]);
}
