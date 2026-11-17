// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0064c9e0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a60a54]
extern const char g_str_newindex_00a60a54[];
// src: EXE [0x00a60a60]
extern const char g_str_metatable_00a60a60[];
// src: EXE [0x00a60a6c]
extern const char g_str_call_00a60a6c[];
// src: EXE [0x00a60a74]
extern const char g_str_Call_00a60a74[];

void SetupCallMetatable_0064c9e0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a60a54);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a60a60);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a60a6c);
    lua_getfield(L, -3, g_str_Call_00a60a74);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
