// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_tonumber callers)
// Reads the first Lua argument as a number and stores it, truncated, as an unsigned int.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct UIntResult_00457340
{
    char m_pad0[4];
    // src: GUESS (confidence: low)
    unsigned int m_value;
};

// src: GUESS (confidence: low) [0x00457340]
void ReadUIntArg_00457340(lua_State* L, UIntResult_00457340* out)
{
    out->m_value = (unsigned int)lua_tonumber(L, 1);
}
