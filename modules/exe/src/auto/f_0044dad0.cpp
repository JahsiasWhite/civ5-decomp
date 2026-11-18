// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_pushnumber callers)
// Pushes both components of a 2-float vector onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Vec2_0044dad0
{
    float x;
    float y;
};

// src: GUESS (confidence: low) [0x0044dad0]
void PushVec2_0044dad0(lua_State* L, const Vec2_0044dad0* v)
{
    lua_pushnumber(L, v->x);
    lua_pushnumber(L, v->y);
}
