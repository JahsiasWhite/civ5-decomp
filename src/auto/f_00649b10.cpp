// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00649b10]

#include "LuaApi.h"

// src: EXE [0x00a62b20]
extern const char g_str_Event_00a62b20[];
// src: EXE [0x00a62b28]
extern const char g_str_index_00a62b28[];
// src: EXE [0x00a62b30]
extern const char g_str_newindex_00a62b30[];

void SetupEventTable_00649b10(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a62b20);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a62b28);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a62b30);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
