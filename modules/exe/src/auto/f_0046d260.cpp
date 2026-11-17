// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0046d260]

#include "LuaApi.h"

// src: EXE [0x00a6495c]
extern const char g_str_Event_00a6495c[];
// src: EXE [0x00a64964]
extern const char g_str_index_00a64964[];
// src: EXE [0x00a6496c]
extern const char g_str_newindex_00a6496c[];

void SetupEventTable_0046d260(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_Event_00a6495c);
    lua_pushvalue(L, idx);
    lua_rawset(L, -3);
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_index_00a64964);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_newindex_00a6496c);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
