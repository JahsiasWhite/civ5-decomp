// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x004ab570]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a5a8a0]
extern const char g_str_newindex_00a5a8a0[];
// src: EXE [0x00a5a8ac]
extern const char g_str_metatable_00a5a8ac[];
// src: EXE [0x00a5a8b8]
extern const char g_str_call_00a5a8b8[];
// src: EXE [0x00a5a8c0]
extern const char g_str_Call_00a5a8c0[];

void SetupCallMetatable_004ab570(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a5a8a0);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a5a8ac);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5a8b8);
    lua_getfield(L, -3, g_str_Call_00a5a8c0);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
