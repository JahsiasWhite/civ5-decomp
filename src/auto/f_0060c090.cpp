// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0060c090]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a58f30]
extern const char g_str_newindex_00a58f30[];
// src: EXE [0x00a58f3c]
extern const char g_str_metatable_00a58f3c[];
// src: EXE [0x00a58f48]
extern const char g_str_call_00a58f48[];
// src: EXE [0x00a58f50]
extern const char g_str_Call_00a58f50[];

void SetupCallMetatable_0060c090(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a58f30);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a58f3c);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a58f48);
    lua_getfield(L, -3, g_str_Call_00a58f50);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
