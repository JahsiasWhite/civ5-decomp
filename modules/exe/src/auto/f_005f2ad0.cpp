// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x005f2ad0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a5f45c]
extern const char g_str_newindex_00a5f45c[];
// src: EXE [0x00a5f468]
extern const char g_str_metatable_00a5f468[];
// src: EXE [0x00a5f474]
extern const char g_str_call_00a5f474[];
// src: EXE [0x00a5f47c]
extern const char g_str_Call_00a5f47c[];

void SetupCallMetatable_005f2ad0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a5f45c);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a5f468);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5f474);
    lua_getfield(L, -3, g_str_Call_00a5f47c);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
