#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00904ea0]
struct LuaRef_00904ea0 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iRef;

    // src: GUESS (confidence: high) [0x00904ea0]
    LuaRef_00904ea0(const LuaRef_00904ea0& other);
};

// src: GUESS (confidence: high) [0x00904ea0]
LuaRef_00904ea0::LuaRef_00904ea0(const LuaRef_00904ea0& other)
    : m_pkLuaState(other.m_pkLuaState)
    , m_iRef(LUA_NOREF)
{
    if (other.m_pkLuaState != 0 && other.m_iRef != LUA_NOREF) {
        lua_checkstack(m_pkLuaState, 1);
        lua_rawgeti(m_pkLuaState, LUA_REGISTRYINDEX, other.m_iRef);
        m_iRef = luaL_ref(m_pkLuaState, LUA_REGISTRYINDEX);
    }
}
