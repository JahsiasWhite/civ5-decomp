// Pushes two shorts and an int onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_005441b0
{
    short m_a;
    short m_b;
    int m_c;
};

// src: GUESS (confidence: low) [0x005441b0]
void PushRecord_005441b0(lua_State* L, const Record_005441b0* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushinteger(L, r->m_c);
}
