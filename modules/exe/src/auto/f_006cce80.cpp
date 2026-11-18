#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_006cce80
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

// src: GUESS (confidence: high) [0x006cce80]
void ReadData_006cce80(lua_State* L, Unk_006cce80* s)
{
    s->m_f14 = (short)lua_tointeger(L, 1);
    s->m_f16 = (short)lua_tointeger(L, 2);
    s->m_f0c = lua_tointeger(L, 3);
    s->m_f10 = lua_tointeger(L, 4);
    s->m_f08 = lua_tointeger(L, 5);
    s->m_f04 = lua_tointeger(L, 6);
    s->m_f00 = lua_tointeger(L, 7);
    s->m_f1c = lua_tointeger(L, 8);
    s->m_f20 = lua_tointeger(L, 9);
}
