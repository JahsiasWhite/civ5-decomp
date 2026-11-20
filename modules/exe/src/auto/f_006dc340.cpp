#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006dc340]
void PushPairRev_006dc340(lua_State* L, const int* p)
{
    lua_pushinteger(L, p[1]);
    lua_pushinteger(L, p[0]);
}
