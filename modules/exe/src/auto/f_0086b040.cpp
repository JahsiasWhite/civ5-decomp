#include "LuaApi.h"

// src: GUESS (confidence: high) [0x009052a0]
struct LuaRef_009052a0 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iRef;

    // src: GUESS (confidence: high) [0x009052a0]
    bool IsTable() const;
};

// src: GUESS (confidence: high) [0x009052a0]
bool LuaRef_009052a0::IsTable() const {
    bool result = false;
    if (m_pkLuaState != 0 && m_iRef != LUA_NOREF) {
        lua_checkstack(m_pkLuaState, 1);
        lua_rawgeti(m_pkLuaState, LUA_REGISTRYINDEX, m_iRef);
        lua_State* L = m_pkLuaState;
        result = (lua_type(L, -1) == LUA_TTABLE);
        lua_settop(L, -2);
    }
    return result;
}
