#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_006caa00
{
    short m_f00;
    short m_f02;
    int m_f04;
    bool m_f08;
};

// src: GUESS (confidence: high) [0x006caa00]
void ReadData_006caa00(lua_State* L, Unk_006caa00* s)
{
    s->m_f00 = (short)lua_tointeger(L, 1);
    s->m_f02 = (short)lua_tointeger(L, 2);
    s->m_f04 = lua_tointeger(L, 3);
    s->m_f08 = (lua_toboolean(L, 4) == 1);
}
