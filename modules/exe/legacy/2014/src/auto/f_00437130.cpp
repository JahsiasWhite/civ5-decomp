// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00437130]

#include "LuaApi.h"

// src: EXE [0x00a635e8]
extern const char g_str_Event_00a635e8[];
// src: EXE [0x00a635f0]
extern const char g_str_index_00a635f0[];
// src: EXE [0x00a635f8]
extern const char g_str_newindex_00a635f8[];

void SetupEventTable_00437130(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a635e8);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a635f0);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a635f8);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
