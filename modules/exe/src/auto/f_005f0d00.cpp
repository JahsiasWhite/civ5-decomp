// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x005f0d00]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a60080]
extern const char g_str_newindex_00a60080[];
// src: EXE [0x00a6008c]
extern const char g_str_metatable_00a6008c[];
// src: EXE [0x00a60098]
extern const char g_str_call_00a60098[];
// src: EXE [0x00a600a0]
extern const char g_str_Call_00a600a0[];

void SetupCallMetatable_005f0d00(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a60080);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a6008c);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a60098);
    lua_getfield(L, -3, g_str_Call_00a600a0);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
