// Lua: calls the upvalue function with this call's arguments after the
// first, discarding its results.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x0073b5c0]
int ForwardCall_0073b5c0(lua_State* L)
{
    int argCount = lua_gettop(L) - 1;
    lua_pushvalue(L, -10003);    // lua_upvalueindex(1)
    lua_insert(L, 2);
    lua_call(L, argCount, 0);
    return 0;
}
