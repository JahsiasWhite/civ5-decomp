#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006d36a0]
void CopyFields_006d36a0(lua_State* L, int idx, const char** names)
{
    for (int i = 0; names[i] != 0; ++i)
    {
        lua_getfield(L, idx, names[i]);
        lua_setfield(L, -2, names[i]);
    }
}
