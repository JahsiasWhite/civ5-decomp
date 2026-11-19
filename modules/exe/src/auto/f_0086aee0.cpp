#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct LuaRef_00905110
{
    lua_State* m_L;
    int m_ref;

    // src: GUESS (confidence: high) [0x00905110]
    int GetType();
};

int LuaRef_00905110::GetType()
{
    if (!m_L || m_ref == LUA_NOREF)
    {
        return -1;
    }
    lua_checkstack(m_L, 1);
    lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_ref);
    int t = lua_type(m_L, -1);
    lua_settop(m_L, -2);
    return t;
}
