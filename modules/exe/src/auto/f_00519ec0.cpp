// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00519ec0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00745180]
int l_Add_00745180(lua_State* L);
// src: EXE [0x00a5e2c0]
extern const char g_str_Add_00a5e2c0[];
// src: GUESS (confidence: high) [0x00763200]
int l_Call_00763200(lua_State* L);
// src: EXE [0x00a5e2c4]
extern const char g_str_Call_00a5e2c4[];
// src: GUESS (confidence: high) [0x00719060]
int l_CallImmediate_00719060(lua_State* L);
// src: EXE [0x00a5e2cc]
extern const char g_str_CallImmediate_00a5e2cc[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5e2dc]
extern const char g_str_Count_00a5e2dc[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5e2e4]
extern const char g_str_Dispatch_00a5e2e4[];
// src: GUESS (confidence: high) [0x007a0fd0]
int l_Remove_007a0fd0(lua_State* L);
// src: EXE [0x00a5e2f0]
extern const char g_str_Remove_00a5e2f0[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5e2f8]
extern const char g_str_RemoveAll_00a5e2f8[];

void RegisterEventMethods_00519ec0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00745180, 1);
    lua_setfield(L, -3, g_str_Add_00a5e2c0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_00763200, 1);
    lua_setfield(L, -3, g_str_Call_00a5e2c4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00719060, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5e2cc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5e2dc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5e2e4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_007a0fd0, 1);
    lua_setfield(L, -3, g_str_Remove_00a5e2f0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5e2f8);
}
