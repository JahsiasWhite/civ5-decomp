#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0046d330
{
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    short m_f14;
    short m_f16;
};

// src: GUESS (confidence: high) [0x0046d330]
void ReadData_0046d330(lua_State* L, Unk_0046d330* s)
{
    s->m_f00 = lua_tointeger(L, 1);
    s->m_f04 = lua_tointeger(L, 2);
    s->m_f08 = lua_tointeger(L, 3);
    s->m_f0c = lua_tointeger(L, 4);
    s->m_f10 = lua_tointeger(L, 5);
    s->m_f14 = (short)lua_tointeger(L, 6);
    s->m_f16 = (short)lua_tointeger(L, 7);
}
