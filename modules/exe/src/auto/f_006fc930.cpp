#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_006fc930
{
    short m_f00;
    short m_f02;
    int m_f04;
    bool m_f08;
};

// src: GUESS (confidence: high) [0x006fc930]
void PushData_006fc930(lua_State* L, const Unk_006fc930* s)
{
    lua_pushinteger(L, s->m_f00);
    lua_pushinteger(L, s->m_f02);
    lua_pushinteger(L, s->m_f04);
    lua_pushboolean(L, s->m_f08);
}
