// Pushes two ints and a flag onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_00726860
{
    int m_a;
    int m_b;
    bool m_flag;
};

// src: GUESS (confidence: low) [0x00726860]
void PushRecord_00726860(lua_State* L, const Record_00726860* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushboolean(L, r->m_flag);
}
