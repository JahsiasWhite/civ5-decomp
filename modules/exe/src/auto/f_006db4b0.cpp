// c5d-cflags: -/arch:SSE2
#include "LuaApi.h"

// src: GUESS (confidence: low)
struct FloatInt_006db4b0
{
    float m_f;  // +0x00
    int m_i;    // +0x04
};

// src: GUESS (confidence: high) [0x006db4b0]
void PushFloatInt_006db4b0(lua_State* L, const FloatInt_006db4b0* p)
{
    lua_pushinteger(L, p->m_i);
    lua_pushnumber(L, p->m_f);
}
