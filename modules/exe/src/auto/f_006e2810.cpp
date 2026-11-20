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

// src: GUESS (confidence: low) [0x006e2770]
int ProtectedBody_006e2770(lua_State* L);

// src: GUESS (confidence: low) [0x006e2810]
int RunProtected_006e2810()
{
    return lua_cpcall(g_pLuaHost_02dd207c->m_L, ProtectedBody_006e2770, 0);
}
