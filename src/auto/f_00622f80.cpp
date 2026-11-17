// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00622f80]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a5d084]
extern const char g_str_newindex_00a5d084[];
// src: EXE [0x00a5d090]
extern const char g_str_metatable_00a5d090[];
// src: EXE [0x00a5d09c]
extern const char g_str_call_00a5d09c[];
// src: EXE [0x00a5d0a4]
extern const char g_str_Call_00a5d0a4[];

void SetupCallMetatable_00622f80(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a5d084);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a5d090);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5d09c);
    lua_getfield(L, -3, g_str_Call_00a5d0a4);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
