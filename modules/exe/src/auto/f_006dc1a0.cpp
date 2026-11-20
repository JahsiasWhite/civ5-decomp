// c5d-cflags: -/arch:SSE2
#include "LuaApi.h"

// src: GUESS (confidence: low)
struct IntFloat_006dc1a0
{
    int m_i;    // +0x00
    float m_f;  // +0x04
};

// src: GUESS (confidence: high) [0x006dc1a0]
void PushIntFloat_006dc1a0(lua_State* L, const IntFloat_006dc1a0* p)
{
    lua_pushinteger(L, p->m_i);
    lua_pushnumber(L, p->m_f);
}
