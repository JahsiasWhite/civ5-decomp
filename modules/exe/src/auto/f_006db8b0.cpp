// c5d-cflags: -/arch:SSE2
#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006db8b0]
void PushUInt_006db8b0(lua_State* L, const unsigned int* p)
{
    lua_pushnumber(L, (double)*p);
}
