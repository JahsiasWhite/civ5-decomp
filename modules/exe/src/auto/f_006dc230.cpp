// Reads two ints and a number from Lua arguments 1-3 into the record.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_0050c800
{
    // src: GUESS (confidence: low)
    int m_second;
    // src: GUESS (confidence: low)
    int m_first;
    char m_pad8[0x20 - 8];
    // src: GUESS (confidence: low)
    float m_value;
};

// src: GUESS (confidence: low) [0x0050c800]
void ReadFromLua_0050c800(lua_State* L, Record_0050c800* r)
{
    r->m_first = lua_tointeger(L, 1);
    r->m_second = lua_tointeger(L, 2);
    r->m_value = (float)lua_tonumber(L, 3);
}
