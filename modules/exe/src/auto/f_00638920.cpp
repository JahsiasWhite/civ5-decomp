// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00638920]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0073b5c0]
int l_CallWrapper_0073b5c0(lua_State* L);
// src: EXE [0x00a5f8fc]
extern const char g_str_newindex_00a5f8fc[];
// src: EXE [0x00a5f908]
extern const char g_str_metatable_00a5f908[];
// src: EXE [0x00a5f914]
extern const char g_str_call_00a5f914[];
// src: EXE [0x00a5f91c]
extern const char g_str_Call_00a5f91c[];

void SetupCallMetatable_00638920(lua_State* L) {
    lua_createtable(L, 0, 3);
    lua_pushstring(L, g_str_newindex_00a5f8fc);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_metatable_00a5f908);
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_call_00a5f914);
    lua_getfield(L, -3, g_str_Call_00a5f91c);
    lua_pushcclosure(L, l_CallWrapper_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
