#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006dc5f0]
void ReadShortPairRev_006dc5f0(lua_State* L, short* p)
{
    short b = (short)lua_tointeger(L, 2);
    int a = lua_tointeger(L, 1);
    p[1] = b;
    p[0] = (short)a;
}
