// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0041ea40]

#include "LuaApi.h"

// src: EXE [0x00a6297c]
extern const char g_str_Event_00a6297c[];
// src: EXE [0x00a62984]
extern const char g_str_index_00a62984[];
// src: EXE [0x00a6298c]
extern const char g_str_newindex_00a6298c[];

void SetupEventTable_0041ea40(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a6297c);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a62984);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a6298c);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
