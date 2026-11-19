#include "LuaApi.h"

// src: GUESS (confidence: low) [0x02dd207c]
struct UnkLuaHost_02dd207c
{
    char m_pad0[0x81900];
    // src: GUESS (confidence: low)
    lua_State* m_L;
};

// src: GUESS (confidence: low) [0x02dd207c]
extern UnkLuaHost_02dd207c* g_pLuaHost_02dd207c;

// src: GUESS (confidence: low) [0x00410c40]
int ProtectedBody_00410c40(lua_State* L);

// Runs ProtectedBody_00410c40 in protected mode on the host's Lua state.
// src: GUESS (confidence: low) [0x00722e00]
int RunProtected_00722e00(void* pUserData)
{
    return lua_cpcall(g_pLuaHost_02dd207c->m_L, ProtectedBody_00410c40, pUserData);
}
