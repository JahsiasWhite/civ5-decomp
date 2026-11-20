#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006dc460]
void ReadIntPairRev_006dc460(lua_State* L, int* p)
{
    p[1] = lua_tointeger(L, 1);
    p[0] = lua_tointeger(L, 2);
}
