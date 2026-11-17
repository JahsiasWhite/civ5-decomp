// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x004622d0]

#include "LuaApi.h"

// src: EXE [0x00a64dd0]
extern const char g_str_Event_00a64dd0[];
// src: EXE [0x00a64dd8]
extern const char g_str_index_00a64dd8[];
// src: EXE [0x00a64de0]
extern const char g_str_newindex_00a64de0[];

void SetupEventTable_004622d0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a64dd0);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a64dd8);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a64de0);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
