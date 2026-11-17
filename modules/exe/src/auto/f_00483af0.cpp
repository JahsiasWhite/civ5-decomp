// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00483af0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a59be8]
extern const char g_str_newindex_00a59be8[];
// src: EXE [0x00a59bf4]
extern const char g_str_metatable_00a59bf4[];
// src: EXE [0x00a59c00]
extern const char g_str_call_00a59c00[];
// src: EXE [0x00a59c08]
extern const char g_str_Call_00a59c08[];

void SetupCallMetatable_00483af0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a59be8);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a59bf4);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a59c00);
    lua_getfield(L, -3, g_str_Call_00a59c08);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
