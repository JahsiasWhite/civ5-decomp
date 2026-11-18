// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_pushnumber callers)
// Pushes the two ints after the header onto the Lua stack as numbers.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Pair_0051e6a0
{
    int m_header;
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low) [0x0051e6a0]
void PushPair_0051e6a0(lua_State* L, const Pair_0051e6a0* p)
{
    lua_pushnumber(L, p->m_a);
    lua_pushnumber(L, p->m_b);
}
