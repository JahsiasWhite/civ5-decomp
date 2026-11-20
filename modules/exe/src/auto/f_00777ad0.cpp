#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00777ad0]
int l_RefreshIncludeFileList_00777ad0(lua_State* L)
{
    lua_getfield(L, LUA_GLOBALSINDEX, "RefreshIncludeFileList");
    lua_call(L, 0, 0);
    return 0;
}
