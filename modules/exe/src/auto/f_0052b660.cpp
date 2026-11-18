// Reads two ints and a flag from Lua arguments 1-3 into the record.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_0052b660
{
    // src: GUESS (confidence: low)
    int m_second;
    // src: GUESS (confidence: low)
    int m_first;
    char m_pad8[0x14 - 8];
    // src: GUESS (confidence: low)
    int m_flag;
};

// src: GUESS (confidence: low) [0x0052b660]
void ReadFromLua_0052b660(lua_State* L, Record_0052b660* r)
{
    r->m_first = lua_tointeger(L, 1);
    r->m_second = lua_tointeger(L, 2);
    r->m_flag = lua_toboolean(L, 3);
}
