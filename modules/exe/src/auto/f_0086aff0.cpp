#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct LuaRef_00905250
{
    lua_State* m_L;
    int m_ref;

    // src: GUESS (confidence: high) [0x00905250]
    bool IsString();
};

bool LuaRef_00905250::IsString()
{
    if (!m_L || m_ref == LUA_NOREF)
    {
        return false;
    }
    lua_checkstack(m_L, 1);
    lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_ref);
    lua_State* L = m_L;
    if (lua_isstring(L, -1))
    {
        return true;
    }
    lua_settop(L, -2);
    return false;
}
