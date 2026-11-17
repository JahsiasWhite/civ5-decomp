// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x004d82d0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a5bc48]
extern const char g_str_newindex_00a5bc48[];
// src: EXE [0x00a5bc54]
extern const char g_str_metatable_00a5bc54[];
// src: EXE [0x00a5bc60]
extern const char g_str_call_00a5bc60[];
// src: EXE [0x00a5bc68]
extern const char g_str_Call_00a5bc68[];

void SetupCallMetatable_004d82d0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a5bc48);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a5bc54);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5bc60);
    lua_getfield(L, -3, g_str_Call_00a5bc68);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
