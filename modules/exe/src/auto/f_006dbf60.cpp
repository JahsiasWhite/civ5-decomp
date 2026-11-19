// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_pushnumber callers)
// Pushes both components of an int pair onto the Lua stack as numbers.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct IntPair_007b4690
{
    int x;
    int y;
};

// src: GUESS (confidence: low) [0x007b4690]
void PushIntPair_007b4690(lua_State* L, const IntPair_007b4690* pair)
{
    lua_pushnumber(L, pair->x);
    lua_pushnumber(L, pair->y);
}
