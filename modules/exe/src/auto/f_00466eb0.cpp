#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_00466eb0
{
    int m_f00;
    int m_f04;
    int m_f08;
    short m_f0c;
    short m_f0e;
};

// src: GUESS (confidence: high) [0x00466eb0]
void PushData_00466eb0(lua_State* L, const Unk_00466eb0* s)
{
    lua_pushinteger(L, s->m_f0c);
    lua_pushinteger(L, s->m_f0e);
    lua_pushinteger(L, s->m_f04);
    lua_pushinteger(L, s->m_f00);
    lua_pushinteger(L, s->m_f08);
}
