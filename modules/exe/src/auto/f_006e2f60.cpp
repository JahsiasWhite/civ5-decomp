#include "LuaApi.h"

// src: GUESS (confidence: high) [0x004d9490]
void InitContentType_004d9490(lua_State* L)
{
    lua_getfield(L, -1, "ContentType");
    if (lua_type(L, -1) == 0)
    {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, "ContentType");
    }
    lua_pushinteger(L, 1);
    lua_setfield(L, -2, "GAMEPLAY");
    lua_pushinteger(L, 2);
    lua_setfield(L, -2, "UISKIN");
    lua_pushinteger(L, 0);
    lua_setfield(L, -2, "COMMON");
    lua_checkstack(L, 1);
    lua_settop(L, -2);
}
