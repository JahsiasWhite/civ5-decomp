#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0050e840
{
    int m_f00;
    int m_f04;
    int m_pad08[3];
    int m_f14;
    int m_f18;
};

// src: GUESS (confidence: high) [0x0050e840]
void ReadData_0050e840(lua_State* L, Unk_0050e840* s)
{
    s->m_f04 = lua_tointeger(L, 1);
    s->m_f00 = lua_tointeger(L, 2);
    s->m_f14 = lua_tointeger(L, 3);
    s->m_f18 = lua_tointeger(L, 4);
}
