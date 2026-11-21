#include "LuaApi.h"

// src: LIB [0x00889684]
extern "C" int luaL_optinteger(lua_State* L, int numArg, int def);

// src: GUESS (confidence: low)
struct UnkSubD0_0075ab50
{
    virtual void V0(bool flag) {}
};

// src: EXE
struct EngineOwner_0075ab50
{
    char m_pad[0xd0];
    UnkSubD0_0075ab50* m_sub;
};

// src: EXE [0x00b49338]
extern EngineOwner_0075ab50* g_pEngineOwner_00cc8e74;

// src: GUESS (confidence: high) [0x0075ab50]
int LuaSetFlagD0_0075ab50(lua_State* L)
{
    UnkSubD0_0075ab50* sub = g_pEngineOwner_00cc8e74->m_sub;
    bool flag = (luaL_optinteger(L, 1, 0) != 0);
    sub->V0(flag);
    return 0;
}
