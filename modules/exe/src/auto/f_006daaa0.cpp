// Reads two shorts and an int from Lua arguments 1-3 into the record.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_0068a740
{
    short m_a;
    short m_b;
    int m_c;
};

// src: GUESS (confidence: low) [0x0068a740]
void ReadFromLua_0068a740(lua_State* L, Record_0068a740* r)
{
    r->m_a = (short)lua_tointeger(L, 1);
    r->m_b = (short)lua_tointeger(L, 2);
    r->m_c = lua_tointeger(L, 3);
}
