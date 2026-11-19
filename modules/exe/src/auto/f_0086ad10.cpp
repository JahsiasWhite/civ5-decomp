#include "LuaApi.h"

extern "C" {
// src: LIB
__declspec(dllimport) void __cdecl _wassert(const wchar_t* message, const wchar_t* file, unsigned line);
}

// src: GUESS (confidence: high) [0x00904f40]
struct LuaRef_00904f40 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iRef;

    // src: GUESS (confidence: high) [0x00904f40]
    LuaRef_00904f40(lua_State* L, int idx);
};

// src: GUESS (confidence: high) [0x00904f40]
LuaRef_00904f40::LuaRef_00904f40(lua_State* L, int idx)
    : m_pkLuaState(L)
    , m_iRef(LUA_NOREF)
{
    if (!L) {
        _wassert(L"m_pkLuaState", L"..\\Source\\FLuaTypes.cpp\0", 0x37);
    }
    lua_checkstack(m_pkLuaState, 1);
    lua_pushvalue(m_pkLuaState, idx);
    m_iRef = luaL_ref(m_pkLuaState, LUA_REGISTRYINDEX);
}
