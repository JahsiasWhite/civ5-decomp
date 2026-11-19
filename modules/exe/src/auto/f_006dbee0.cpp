// Pushes an int and two flags onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_00720740
{
    int m_value;
    bool m_first;
    bool m_second;
};

// src: GUESS (confidence: low) [0x00720740]
void PushRecord_00720740(lua_State* L, const Record_00720740* r)
{
    lua_pushinteger(L, r->m_value);
    lua_pushboolean(L, r->m_first);
    lua_pushboolean(L, r->m_second);
}
