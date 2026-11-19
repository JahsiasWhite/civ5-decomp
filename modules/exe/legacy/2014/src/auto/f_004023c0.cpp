// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/GF
// src: GUESS (confidence: high) [0x004023c0]

#include "LuaApi.h"

// src: EXE [0x00a634f8]
extern const char g_str_Event_00a634f8[];
// src: EXE [0x00a63500]
extern const char g_str_index_00a63500[];
// src: EXE [0x00a63508]
extern const char g_str_newindex_00a63508[];

void SetupEventTable_004023c0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a634f8);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a63500);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a63508);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
