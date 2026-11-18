// Pushes two ints and whether a third is set onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_005ccc20
{
    int m_b;
    int m_a;
    char m_pad8[0x14 - 8];
    int m_flag;
};

// src: GUESS (confidence: low) [0x005ccc20]
void PushRecord_005ccc20(lua_State* L, const Record_005ccc20* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushboolean(L, r->m_flag != 0);
}
