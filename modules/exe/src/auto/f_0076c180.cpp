#include "LuaApi.h"

// src: GUESS (confidence: low)
struct UnkSubSystem_0076c180
{
    virtual void V0() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void V8() {}
    virtual void V9() {}
    virtual void V10() {}
    virtual void V11() {}
    virtual void V12() {}
    virtual void V13() {}
    virtual void V14() {}
    virtual void V15() {}
    virtual void V16() {}
    virtual void V17() {}
    virtual void V18() {}
    virtual void V19() {}
    virtual void V20() {}
    virtual void V21() {}
    virtual void V22() {}
    virtual void V23() {}
    virtual void V24(int a, int b) {}
};

// src: EXE
struct EngineOwner_0076c180
{
    char m_pad[0x1460];
    UnkSubSystem_0076c180* m_sub;
};

// src: EXE [0x00b49338]
extern EngineOwner_0076c180* g_pEngineOwner_00cc8e74;

// src: LIB [0x00889606]
extern "C" int luaL_checkinteger(lua_State* L, int numArg);

// src: GUESS (confidence: high) [0x0076c180]
int LuaCallSub24_0076c180(lua_State* L)
{
    int a = luaL_checkinteger(L, 1);
    int b = luaL_checkinteger(L, 2);
    g_pEngineOwner_00cc8e74->m_sub->V24(a, b);
    return 0;
}
