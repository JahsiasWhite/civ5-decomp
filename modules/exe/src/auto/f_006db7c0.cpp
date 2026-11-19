// Pushes the three ints after the header onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Triple_004c3620
{
    int m_header;
    int m_a;
    int m_b;
    int m_c;
};

// src: GUESS (confidence: low) [0x004c3620]
void PushTriple_004c3620(lua_State* L, const Triple_004c3620* t)
{
    lua_pushinteger(L, t->m_a);
    lua_pushinteger(L, t->m_b);
    lua_pushinteger(L, t->m_c);
}
