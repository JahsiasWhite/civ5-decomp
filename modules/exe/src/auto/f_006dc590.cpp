#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0061a8e0
{
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    bool m_f14;
    bool m_f15;
};

// src: GUESS (confidence: high) [0x0061a8e0]
void PushData_0061a8e0(lua_State* L, const Unk_0061a8e0* s)
{
    lua_pushinteger(L, s->m_f00);
    lua_pushinteger(L, s->m_f04);
    lua_pushinteger(L, s->m_f08);
    lua_pushinteger(L, s->m_f0c);
    lua_pushinteger(L, s->m_f10);
    lua_pushboolean(L, s->m_f14);
    lua_pushboolean(L, s->m_f15);
}
