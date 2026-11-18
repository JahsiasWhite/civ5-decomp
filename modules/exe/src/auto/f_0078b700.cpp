#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_0078b700
{
    short m_f00;
    short m_f02;
    int m_f04;
    int m_f08;
};

// src: GUESS (confidence: high) [0x0078b700]
void PushData_0078b700(lua_State* L, const Unk_0078b700* s)
{
    lua_pushinteger(L, s->m_f00);
    lua_pushinteger(L, s->m_f02);
    lua_pushinteger(L, s->m_f04);
    lua_pushinteger(L, s->m_f08);
}
