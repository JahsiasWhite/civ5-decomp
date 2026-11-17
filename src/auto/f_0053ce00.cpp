// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0053ce00]

#include "LuaApi.h"

// src: EXE [0x00a63ed0]
extern const char g_str_Event_00a63ed0[];
// src: EXE [0x00a63ed8]
extern const char g_str_index_00a63ed8[];
// src: EXE [0x00a63ee0]
extern const char g_str_newindex_00a63ee0[];

void SetupEventTable_0053ce00(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a63ed0);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a63ed8);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a63ee0);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
