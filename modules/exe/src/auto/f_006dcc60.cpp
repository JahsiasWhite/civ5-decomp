#include "LuaApi.h"

// src: GUESS (confidence: low)
struct UnkPair_005dd2c0
{
    short m_a;
    short m_b;
};

// src: GUESS (confidence: low)
struct Unk_005dd2c0
{
    int m_f00;
    UnkPair_005dd2c0 m_f04;
};

// src: GUESS (confidence: high) [0x005dd2c0]
void ReadData_005dd2c0(lua_State* L, Unk_005dd2c0* s)
{
    UnkPair_005dd2c0 p;
    p.m_a = (short)lua_tointeger(L, 1);
    p.m_b = (short)lua_tointeger(L, 2);
    s->m_f04 = p;
    s->m_f00 = lua_tointeger(L, 3);
}
