#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0076c170
{
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    short m_f14;
    short m_f16;
    int m_pad18;
    int m_f1c;
    int m_f20;
};

// src: GUESS (confidence: high) [0x0076c170]
void PushData_0076c170(lua_State* L, const Unk_0076c170* s)
{
    lua_pushinteger(L, s->m_f14);
    lua_pushinteger(L, s->m_f16);
    lua_pushinteger(L, s->m_f0c);
    lua_pushinteger(L, s->m_f10);
    lua_pushinteger(L, s->m_f08);
    lua_pushinteger(L, s->m_f04);
    lua_pushinteger(L, s->m_f00);
    lua_pushinteger(L, s->m_f1c);
    lua_pushinteger(L, s->m_f20);
}
