#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct LuaRef_00905160
{
    lua_State* m_L;
    int m_ref;

    // src: GUESS (confidence: high) [0x00905160]
    const char* GetTypeName();
};

const char* LuaRef_00905160::GetTypeName()
{
    if (m_L)
    {
        if (m_ref != LUA_NOREF)
        {
            lua_checkstack(m_L, 1);
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_ref);
            int t = lua_type(m_L, -1);
            lua_settop(m_L, -2);
            return lua_typename(m_L, t);
        }
        return lua_typename(m_L, -1);
    }
    return "Invalid\0";
}
