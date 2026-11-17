// Lua-to-C conversion stub that must never run: raises a Lua error. The exe
// keeps a separate copy of this message for each such stub.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x00a56370]
extern const char kDontCallThis_00657870[] = "Don't call this";

// src: GUESS (confidence: low) [0x00657870]
void RejectFromLua_00657870(lua_State* L, int idx)
{
    luaL_error(L, kDontCallThis_00657870);
}
