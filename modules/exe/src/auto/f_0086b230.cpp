// Releases the held Lua registry reference, if any, and resets it.

#include "LuaApi.h"

// src: GUESS (confidence: low)
class LuaRef_00905220
{
public:
    // src: GUESS (confidence: low) [0x00905220]
    void Release();

    // src: GUESS (confidence: low)
    lua_State* m_L;
    // src: GUESS (confidence: low)
    int m_ref;
};

void LuaRef_00905220::Release()
{
    if (m_L && m_ref != -2)
        luaL_unref(m_L, -10000, m_ref);    // LUA_REGISTRYINDEX; -2 is LUA_NOREF
    m_L = 0;
    m_ref = -2;
}
