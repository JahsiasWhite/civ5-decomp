// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00661c00]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x007a1280]
int l_Add_007a1280(lua_State* L);
// src: EXE [0x00a598c0]
extern const char g_str_Add_00a598c0[];
// src: GUESS (confidence: high) [0x007755d0]
int l_Call_007755d0(lua_State* L);
// src: EXE [0x00a598c4]
extern const char g_str_Call_00a598c4[];
// src: GUESS (confidence: high) [0x00680f30]
int l_CallImmediate_00680f30(lua_State* L);
// src: EXE [0x00a598cc]
extern const char g_str_CallImmediate_00a598cc[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a598dc]
extern const char g_str_Count_00a598dc[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a598e4]
extern const char g_str_Dispatch_00a598e4[];
// src: GUESS (confidence: high) [0x00657cf0]
int l_Remove_00657cf0(lua_State* L);
// src: EXE [0x00a598f0]
extern const char g_str_Remove_00a598f0[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a598f8]
extern const char g_str_RemoveAll_00a598f8[];

void RegisterEventMethods_00661c00(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_007a1280, 1);
    lua_setfield(L, -3, g_str_Add_00a598c0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_007755d0, 1);
    lua_setfield(L, -3, g_str_Call_00a598c4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00680f30, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a598cc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a598dc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a598e4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00657cf0, 1);
    lua_setfield(L, -3, g_str_Remove_00a598f0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a598f8);
}
