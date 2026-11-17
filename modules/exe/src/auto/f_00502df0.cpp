// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00502df0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a61d68]
extern const char g_str_newindex_00a61d68[];
// src: EXE [0x00a61d74]
extern const char g_str_metatable_00a61d74[];
// src: EXE [0x00a61d80]
extern const char g_str_call_00a61d80[];
// src: EXE [0x00a61d88]
extern const char g_str_Call_00a61d88[];

void SetupCallMetatable_00502df0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a61d68);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a61d74);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a61d80);
    lua_getfield(L, -3, g_str_Call_00a61d88);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
