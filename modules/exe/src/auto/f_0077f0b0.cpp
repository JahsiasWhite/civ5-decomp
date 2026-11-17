// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0077f0b0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00424e00]
int l_Add_00424e00(lua_State* L);
// src: EXE [0x00a619ac]
extern const char g_str_Add_00a619ac[];
// src: GUESS (confidence: high) [0x0043d3b0]
int l_Call_0043d3b0(lua_State* L);
// src: EXE [0x00a619b0]
extern const char g_str_Call_00a619b0[];
// src: GUESS (confidence: high) [0x006c6dd0]
int l_CallImmediate_006c6dd0(lua_State* L);
// src: EXE [0x00a619b8]
extern const char g_str_CallImmediate_00a619b8[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a619c8]
extern const char g_str_Count_00a619c8[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a619d0]
extern const char g_str_Dispatch_00a619d0[];
// src: GUESS (confidence: high) [0x00497320]
int l_Remove_00497320(lua_State* L);
// src: EXE [0x00a619dc]
extern const char g_str_Remove_00a619dc[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a619e4]
extern const char g_str_RemoveAll_00a619e4[];

void RegisterEventMethods_0077f0b0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00424e00, 1);
    lua_setfield(L, -3, g_str_Add_00a619ac);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0043d3b0, 1);
    lua_setfield(L, -3, g_str_Call_00a619b0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_006c6dd0, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a619b8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a619c8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a619d0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00497320, 1);
    lua_setfield(L, -3, g_str_Remove_00a619dc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a619e4);
}
