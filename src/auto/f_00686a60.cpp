// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00686a60]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a619f0]
extern const char g_str_newindex_00a619f0[];
// src: EXE [0x00a619fc]
extern const char g_str_metatable_00a619fc[];
// src: EXE [0x00a61a08]
extern const char g_str_call_00a61a08[];
// src: EXE [0x00a61a10]
extern const char g_str_Call_00a61a10[];

void SetupCallMetatable_00686a60(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a619f0);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a619fc);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a61a08);
    lua_getfield(L, -3, g_str_Call_00a61a10);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
