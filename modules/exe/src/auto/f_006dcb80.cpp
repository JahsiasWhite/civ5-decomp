#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_00514100
{
    int m_pad00;
    int m_f04;
    int m_f08;
    unsigned char m_f0c;
    unsigned char m_pad0d;
    short m_f0e;
    short m_f10;
    short m_f12;
    short m_f14;
    short m_f16;
    int m_pad18[4];
    int m_f28;
    int m_f2c;
    unsigned char m_f30;
    unsigned char m_pad31;
    short m_f32;
    short m_f34;
    short m_f36;
    short m_f38;
    short m_f3a;
};

// src: GUESS (confidence: high) [0x00514100]
void PushData_00514100(lua_State* L, const Unk_00514100* s)
{
    lua_pushinteger(L, s->m_f04);
    lua_pushinteger(L, (s->m_f04 != -1 && s->m_f08 != -1 && !(s->m_f0c & 1)) ? s->m_f08 : -1);
    lua_pushinteger(L, s->m_f0e);
    lua_pushinteger(L, s->m_f10);
    lua_pushinteger(L, s->m_f12);
    lua_pushinteger(L, s->m_f28);
    lua_pushinteger(L, (s->m_f28 != -1 && s->m_f2c != -1 && !(s->m_f30 & 1)) ? s->m_f2c : -1);
    lua_pushinteger(L, s->m_f32);
    lua_pushinteger(L, s->m_f34);
    lua_pushinteger(L, s->m_f36);
    lua_pushinteger(L, s->m_f14);
    lua_pushinteger(L, s->m_f16);
    lua_pushinteger(L, s->m_f38);
    lua_pushinteger(L, s->m_f3a);
}
