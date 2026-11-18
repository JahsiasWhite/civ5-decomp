// Pushes four ints onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_00786a00
{
    int m_d;
    int m_c;
    char m_pad8[0x14 - 8];
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low) [0x00786a00]
void PushRecord_00786a00(lua_State* L, const Record_00786a00* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushinteger(L, r->m_c);
    lua_pushinteger(L, r->m_d);
}
