// Reads three ints from Lua arguments 1-3 into the record.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_004a42c0
{
    int m_header;
    int m_a;
    int m_b;
    int m_c;
};

// src: GUESS (confidence: low) [0x004a42c0]
void ReadFromLua_004a42c0(lua_State* L, Record_004a42c0* r)
{
    r->m_a = lua_tointeger(L, 1);
    r->m_b = lua_tointeger(L, 2);
    r->m_c = lua_tointeger(L, 3);
}
