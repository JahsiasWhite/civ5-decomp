#include "LuaApi.h"

extern "C" {
// src: LIB
__declspec(dllimport) void __cdecl _wassert(const wchar_t* message, const wchar_t* file, unsigned line);
}

// src: GUESS (confidence: high) [0x009041f0]
struct LuaStackSlot_009041f0 {
    // src: GUESS (confidence: high)
    lua_State* m_pkLuaState;
    // src: GUESS (confidence: high)
    int m_iIndex;

    // src: GUESS (confidence: high) [0x009041f0]
    LuaStackSlot_009041f0(lua_State* L, int idx);
};

// src: GUESS (confidence: high) [0x009041f0]
LuaStackSlot_009041f0::LuaStackSlot_009041f0(lua_State* L, int idx)
    : m_pkLuaState(L)
    , m_iIndex(idx)
{
    if (!L) {
        _wassert(L"L\0", L"..\\Source\\FLuaCommon.cpp", 0x247);
    }
    if (idx < 0) {
        m_iIndex = lua_gettop(L) + idx + 1;
    }
}
