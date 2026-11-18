#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00904f00]
struct LuaRef_00904f00 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iRef;

    // src: GUESS (confidence: high) [0x00904f00]
    LuaRef_00904f00(const LuaRef_00904f00& other);
};

// src: GUESS (confidence: high) [0x00904f00]
LuaRef_00904f00::LuaRef_00904f00(const LuaRef_00904f00& other)
    : m_pkLuaState(other.m_pkLuaState)
{
    lua_checkstack(other.m_pkLuaState, 1);
    lua_pushvalue(other.m_pkLuaState, other.m_iRef);
    m_iRef = luaL_ref(other.m_pkLuaState, LUA_REGISTRYINDEX);
}
