// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00775ae0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x004fc5a0]
int l_Add_004fc5a0(lua_State* L);
// src: EXE [0x00a5c41c]
extern const char g_str_Add_00a5c41c[];
// src: GUESS (confidence: high) [0x0048ddc0]
int l_Call_0048ddc0(lua_State* L);
// src: EXE [0x00a5c420]
extern const char g_str_Call_00a5c420[];
// src: GUESS (confidence: high) [0x0073e360]
int l_CallImmediate_0073e360(lua_State* L);
// src: EXE [0x00a5c428]
extern const char g_str_CallImmediate_00a5c428[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5c438]
extern const char g_str_Count_00a5c438[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5c440]
extern const char g_str_Dispatch_00a5c440[];
// src: GUESS (confidence: high) [0x00497230]
int l_Remove_00497230(lua_State* L);
// src: EXE [0x00a5c44c]
extern const char g_str_Remove_00a5c44c[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5c454]
extern const char g_str_RemoveAll_00a5c454[];

void RegisterEventMethods_00775ae0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_004fc5a0, 1);
    lua_setfield(L, -3, g_str_Add_00a5c41c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0048ddc0, 1);
    lua_setfield(L, -3, g_str_Call_00a5c420);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_0073e360, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5c428);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5c438);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5c440);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00497230, 1);
    lua_setfield(L, -3, g_str_Remove_00a5c44c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5c454);
}
