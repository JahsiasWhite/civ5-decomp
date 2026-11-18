#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00905440]
struct LuaRef_00905440 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iRef;

    // src: GUESS (confidence: high) [0x00905440]
    bool PushFunction() const;
};

// src: GUESS (confidence: high) [0x00905440]
bool LuaRef_00905440::PushFunction() const {
    if (m_pkLuaState != 0 && m_iRef != LUA_NOREF) {
        lua_checkstack(m_pkLuaState, 1);
        lua_rawgeti(m_pkLuaState, LUA_REGISTRYINDEX, m_iRef);
        lua_State* L = m_pkLuaState;
        if (lua_type(L, -1) == 6) {
            return true;
        }
        lua_settop(L, -2);
    }
    return false;
}
