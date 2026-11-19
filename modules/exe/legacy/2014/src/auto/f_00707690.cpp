// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00707690]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x007af180]
int l_Add_007af180(lua_State* L);
// src: EXE [0x00a61350]
extern const char g_str_Add_00a61350[];
// src: GUESS (confidence: high) [0x0049b490]
int l_Call_0049b490(lua_State* L);
// src: EXE [0x00a61354]
extern const char g_str_Call_00a61354[];
// src: GUESS (confidence: high) [0x0054f930]
int l_CallImmediate_0054f930(lua_State* L);
// src: EXE [0x00a6135c]
extern const char g_str_CallImmediate_00a6135c[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a6136c]
extern const char g_str_Count_00a6136c[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a61374]
extern const char g_str_Dispatch_00a61374[];
// src: GUESS (confidence: high) [0x00584780]
int l_Remove_00584780(lua_State* L);
// src: EXE [0x00a61380]
extern const char g_str_Remove_00a61380[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a61388]
extern const char g_str_RemoveAll_00a61388[];

void RegisterEventMethods_00707690(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_007af180, 1);
    lua_setfield(L, -3, g_str_Add_00a61350);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0049b490, 1);
    lua_setfield(L, -3, g_str_Call_00a61354);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_0054f930, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a6135c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a6136c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a61374);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00584780, 1);
    lua_setfield(L, -3, g_str_Remove_00a61380);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a61388);
}
