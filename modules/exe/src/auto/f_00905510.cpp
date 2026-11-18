#include "LuaApi.h"

extern "C" {
// src: LIB
__declspec(dllimport) void __cdecl _wassert(const wchar_t* message, const wchar_t* file, unsigned line);
}

// src: GUESS (confidence: high) [0x00905510]
struct LuaRef_00905510 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iRef;

    // src: GUESS (confidence: high) [0x00905510]
    void Set(lua_State* L, int idx);
};

// src: GUESS (confidence: high) [0x00905510]
void LuaRef_00905510::Set(lua_State* L, int idx) {
    if (!L) {
        _wassert(L"L", L"..\\Source\\FLuaTypes.cpp", 0x6b);
    }
    if (m_pkLuaState && m_iRef != LUA_NOREF) {
        luaL_unref(m_pkLuaState, LUA_REGISTRYINDEX, m_iRef);
    }
    m_pkLuaState = 0;
    m_iRef = LUA_NOREF;
    if (L) {
        m_pkLuaState = L;
        lua_checkstack(L, 1);
        lua_pushvalue(L, idx);
        m_iRef = luaL_ref(L, LUA_REGISTRYINDEX);
    }
}
