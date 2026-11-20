#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006da900]
void PushShortPair_006da900(lua_State* L, const short* p)
{
    lua_pushinteger(L, p[0]);
    lua_pushinteger(L, p[1]);
}
