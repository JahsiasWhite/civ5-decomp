#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0042f810
{
    short m_f00;
    short m_f02;
    int m_f04;
    int m_f08;
};

// src: GUESS (confidence: high) [0x0042f810]
void ReadData_0042f810(lua_State* L, Unk_0042f810* s)
{
    int type = lua_tointeger(L, 1);
    s->m_f08 = type;
    if (type == 8)
    {
        s->m_f04 = lua_tointeger(L, 2);
        s->m_f00 = (short)lua_tointeger(L, 3);
        s->m_f02 = (short)lua_tointeger(L, 4);
    }
    else if (type == 5 || type == 7 || type == 6)
    {
        s->m_f00 = (short)lua_tointeger(L, 2);
        s->m_f02 = (short)lua_tointeger(L, 3);
    }
}
