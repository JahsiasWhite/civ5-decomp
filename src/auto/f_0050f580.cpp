// Lua-to-C conversion stub that must never run: raises a Lua error. The exe
// keeps a separate copy of this message for each such stub.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x00a56380]
extern const char kDontCallThis_0050f580[] = "Don't call this";

// src: GUESS (confidence: low) [0x0050f580]
void RejectFromLua_0050f580(lua_State* L, int idx)
{
    luaL_error(L, kDontCallThis_0050f580);
}
