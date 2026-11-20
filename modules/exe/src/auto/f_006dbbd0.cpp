#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006dbbd0]
void ReadFloatPair_006dbbd0(lua_State* L, float* p)
{
    p[0] = (float)lua_tonumber(L, 1);
    p[1] = (float)lua_tonumber(L, 2);
}
