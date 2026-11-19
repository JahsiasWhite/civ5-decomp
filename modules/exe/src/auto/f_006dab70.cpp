#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_00694500
{
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    short m_f14;
    short m_f16;
};

// src: GUESS (confidence: high) [0x00694500]
void PushData_00694500(lua_State* L, const Unk_00694500* s)
{
    lua_pushinteger(L, s->m_f00);
    lua_pushinteger(L, s->m_f04);
    lua_pushinteger(L, s->m_f08);
    lua_pushinteger(L, s->m_f0c);
    lua_pushinteger(L, s->m_f10);
    lua_pushinteger(L, s->m_f14);
    lua_pushinteger(L, s->m_f16);
}
