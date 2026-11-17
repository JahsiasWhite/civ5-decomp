// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x004599f0]

#include "LuaApi.h"

// src: EXE [0x00a648e4]
extern const char g_str_Event_00a648e4[];
// src: EXE [0x00a648ec]
extern const char g_str_index_00a648ec[];
// src: EXE [0x00a648f4]
extern const char g_str_newindex_00a648f4[];

void SetupEventTable_004599f0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a648e4);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a648ec);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a648f4);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
