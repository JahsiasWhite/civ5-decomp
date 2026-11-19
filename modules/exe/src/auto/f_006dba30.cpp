// Pushes two shorts and a flag onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_00750270
{
    short m_a;
    short m_b;
    bool m_flag;
};

// src: GUESS (confidence: low) [0x00750270]
void PushRecord_00750270(lua_State* L, const Record_00750270* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushboolean(L, r->m_flag);
}
