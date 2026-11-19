#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0043a4f0
{
    int m_f00;
    int m_f04;
    int m_f08;
    short m_f0c;
    short m_f0e;
};

// src: GUESS (confidence: high) [0x0043a4f0]
void ReadData_0043a4f0(lua_State* L, Unk_0043a4f0* s)
{
    s->m_f0c = (short)lua_tointeger(L, 1);
    s->m_f0e = (short)lua_tointeger(L, 2);
    s->m_f04 = lua_tointeger(L, 3);
    s->m_f00 = lua_tointeger(L, 4);
    s->m_f08 = lua_tointeger(L, 5);
}
