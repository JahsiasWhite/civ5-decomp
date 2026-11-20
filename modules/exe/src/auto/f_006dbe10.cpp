#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006dbe10]
void ReadBool_006dbe10(lua_State* L, bool* out)
{
    *out = (lua_toboolean(L, 1) != 0);
}
