// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00427cf0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a59904]
extern const char g_str_newindex_00a59904[];
// src: EXE [0x00a59910]
extern const char g_str_metatable_00a59910[];
// src: EXE [0x00a5991c]
extern const char g_str_call_00a5991c[];
// src: EXE [0x00a59924]
extern const char g_str_Call_00a59924[];

void SetupCallMetatable_00427cf0(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a59904);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a59910);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5991c);
    lua_getfield(L, -3, g_str_Call_00a59924);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
