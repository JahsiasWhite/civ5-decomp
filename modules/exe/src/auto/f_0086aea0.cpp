// Pushes the referenced Lua value onto the stack; false when there's no
// reference.

#include "LuaApi.h"

// src: GUESS (confidence: low)
class LuaRef_009050d0
{
public:
    // src: GUESS (confidence: low) [0x009050d0]
    bool Push();

    // src: GUESS (confidence: low)
    lua_State* m_L;
    // src: GUESS (confidence: low)
    int m_ref;
};

bool LuaRef_009050d0::Push()
{
    if (!m_L || m_ref == -2)    // LUA_NOREF
        return false;
    lua_checkstack(m_L, 1);
    lua_rawgeti(m_L, -10000, m_ref);    // LUA_REGISTRYINDEX
    return true;
}
