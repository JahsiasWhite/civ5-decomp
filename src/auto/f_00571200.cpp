// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00571200]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a58ce0]
extern const char g_str_newindex_00a58ce0[];
// src: EXE [0x00a58cec]
extern const char g_str_metatable_00a58cec[];
// src: EXE [0x00a58cf8]
extern const char g_str_call_00a58cf8[];
// src: EXE [0x00a58d00]
extern const char g_str_Call_00a58d00[];

void SetupCallMetatable_00571200(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a58ce0);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a58cec);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a58cf8);
    lua_getfield(L, -3, g_str_Call_00a58d00);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
