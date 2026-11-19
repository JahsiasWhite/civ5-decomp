#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_004fc420
{
    int m_pad00;
    int m_f04;
    bool m_f08;
    int m_f0c;
    int m_f10;
    int m_f14;
};

// src: GUESS (confidence: high) [0x004fc420]
void ReadData_004fc420(lua_State* L, Unk_004fc420* s)
{
    s->m_f04 = lua_tointeger(L, 1);
    s->m_f08 = (lua_toboolean(L, 2) != 0);
    s->m_f0c = lua_tointeger(L, 3);
    s->m_f10 = lua_tointeger(L, 4);
    s->m_f14 = lua_tointeger(L, 5);
}
