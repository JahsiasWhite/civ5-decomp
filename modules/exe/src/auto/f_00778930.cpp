#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00778930]
int l_CloudSaveName_00778930(lua_State* L)
{
    lua_pushfstring(L, "CloudSave %d.Civ5Save", luaL_checkinteger(L, 1));
    return 1;
}
