// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0054b9f0]

#include "LuaApi.h"

// src: EXE [0x00a643f8]
extern const char g_str_Event_00a643f8[];
// src: EXE [0x00a64400]
extern const char g_str_index_00a64400[];
// src: EXE [0x00a64408]
extern const char g_str_newindex_00a64408[];

void SetupEventTable_0054b9f0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a643f8);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a64400);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a64408);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
