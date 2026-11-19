// Pushes four ints onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_007b1de0
{
    int m_a;
    int m_c;
    int m_d;
    int m_b;
};

// src: GUESS (confidence: low) [0x007b1de0]
void PushRecord_007b1de0(lua_State* L, const Record_007b1de0* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushinteger(L, r->m_c);
    lua_pushinteger(L, r->m_d);
}
