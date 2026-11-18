// Reads two ints and a flag from Lua arguments 1-3 into the record.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_006eac30
{
    int m_a;
    int m_b;
    bool m_flag;
};

// src: GUESS (confidence: low) [0x006eac30]
void ReadFromLua_006eac30(lua_State* L, Record_006eac30* r)
{
    r->m_a = lua_tointeger(L, 1);
    r->m_b = lua_tointeger(L, 2);
    r->m_flag = lua_toboolean(L, 3) != 0;
}
