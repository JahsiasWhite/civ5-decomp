// c5d-cflags: -/arch:SSE2
// Pushes two ints and a float onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_00533df0
{
    int m_b;
    int m_a;
    char m_pad8[0x20 - 8];
    float m_value;
};

// src: GUESS (confidence: low) [0x00533df0]
void PushRecord_00533df0(lua_State* L, const Record_00533df0* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushnumber(L, r->m_value);
}
