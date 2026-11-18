#include "LuaApi.h"

// src: EXE [0x00444780]
int l_LuaEventFactoryIndex_00444780(lua_State* L);

// src: GUESS (confidence: high) [0x007b4220]
void InitLuaEventFactory_007b4220(lua_State* L)
{
    lua_getfield(L, LUA_GLOBALSINDEX, "LuaEventFactory");
    if (lua_type(L, -1) == 0)
    {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, LUA_GLOBALSINDEX, "LuaEventFactory");
        lua_pushstring(L, "__index\0");
        lua_createtable(L, 0, 0);
        lua_pushcclosure(L, l_LuaEventFactoryIndex_00444780, 1);
        lua_rawset(L, -3);
    }
}
