#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct LuaRef_009051d0
{
    lua_State* m_L;
    int m_ref;

    // src: GUESS (confidence: high) [0x009051d0]
    bool IsNil();
};

bool LuaRef_009051d0::IsNil()
{
    if (!m_L || m_ref == LUA_NOREF)
    {
        return true;
    }
    lua_checkstack(m_L, 1);
    lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_ref);
    bool res = (lua_type(m_L, -1) == 0);
    lua_settop(m_L, -2);
    return res;
}
