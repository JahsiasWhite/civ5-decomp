#include "LuaApi.h"

// src: GUESS (confidence: low) [0x00c93ee4]
extern const char* g_str_00c93ee4;
// src: EXE [0x00718160]
int l_GameEventsIndex_00718160(lua_State* L);

// src: GUESS (confidence: high) [0x00468300]
void InitGameEvents_00468300(lua_State* L)
{
    lua_getfield(L, LUA_GLOBALSINDEX, g_str_00c93ee4);
    if (lua_type(L, -1) == 0)
    {
        lua_settop(L, -2);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, LUA_GLOBALSINDEX, g_str_00c93ee4);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -2);
        lua_setmetatable(L, -2);
        lua_setfield(L, LUA_GLOBALSINDEX, "GameEvents");
        lua_pushstring(L, "__index\0\0");
        lua_createtable(L, 0, 0);
        lua_pushcclosure(L, l_GameEventsIndex_00718160, 1);
        lua_rawset(L, -3);
    }
}
