// Reads two ints and a byte from Lua arguments 1-3 and marks the record set.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_0050c4a0
{
    // src: GUESS (confidence: low)
    unsigned int m_flags;
    int m_a;
    int m_b;
    unsigned char m_c;
};

// src: GUESS (confidence: low) [0x0050c4a0]
void ReadFromLua_0050c4a0(lua_State* L, Record_0050c4a0* r)
{
    r->m_a = lua_tointeger(L, 1);
    r->m_b = lua_tointeger(L, 2);
    r->m_c = (unsigned char)lua_tointeger(L, 3);
    r->m_flags |= 1;
}
