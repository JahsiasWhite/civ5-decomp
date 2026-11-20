#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006e7300]
int l_UpvalueLen_006e7300(lua_State* L)
{
    lua_pushinteger(L, lua_objlen(L, lua_upvalueindex(1)));
    return 1;
}
