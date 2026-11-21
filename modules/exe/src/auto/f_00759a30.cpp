#include "LuaApi.h"

// src: GUESS (confidence: medium) [0x00759a30]
int LuaGetFlag1020_00759a30(lua_State* L)
{
    unsigned char* ud = (unsigned char*)lua_touserdata(L, -10003);
    if (ud)
    {
        lua_pushboolean(L, ud[0x1020]);
        return 1;
    }
    return 0;
}
