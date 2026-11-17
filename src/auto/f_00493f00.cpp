// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00493f00]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a5a650]
extern const char g_str_newindex_00a5a650[];
// src: EXE [0x00a5a65c]
extern const char g_str_metatable_00a5a65c[];
// src: EXE [0x00a5a668]
extern const char g_str_call_00a5a668[];
// src: EXE [0x00a5a670]
extern const char g_str_Call_00a5a670[];

void SetupCallMetatable_00493f00(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a5a650);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a5a65c);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5a668);
    lua_getfield(L, -3, g_str_Call_00a5a670);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
