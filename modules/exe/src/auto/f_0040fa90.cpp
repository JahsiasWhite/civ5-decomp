// Pushes two ints and a byte (after the header) onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_0040fa90
{
    int m_header;
    int m_a;
    int m_b;
    unsigned char m_c;
};

// src: GUESS (confidence: low) [0x0040fa90]
void PushRecord_0040fa90(lua_State* L, const Record_0040fa90* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushinteger(L, r->m_c);
}
