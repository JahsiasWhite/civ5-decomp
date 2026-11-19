#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_004ab3c0
{
    int m_pad00;
    int m_f04;
    bool m_f08;
    int m_f0c;
    int m_f10;
    int m_f14;
};

// src: GUESS (confidence: high) [0x004ab3c0]
void PushData_004ab3c0(lua_State* L, const Unk_004ab3c0* s)
{
    lua_pushinteger(L, s->m_f04);
    lua_pushboolean(L, s->m_f08);
    lua_pushinteger(L, s->m_f0c);
    lua_pushinteger(L, s->m_f10);
    lua_pushinteger(L, s->m_f14);
}
