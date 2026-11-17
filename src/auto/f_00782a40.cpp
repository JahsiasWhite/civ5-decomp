// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00782a40]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00662bd0]
int l_Add_00662bd0(lua_State* L);
// src: EXE [0x00a5b108]
extern const char g_str_Add_00a5b108[];
// src: GUESS (confidence: high) [0x0045e070]
int l_Call_0045e070(lua_State* L);
// src: EXE [0x00a5b10c]
extern const char g_str_Call_00a5b10c[];
// src: GUESS (confidence: high) [0x006fdd00]
int l_CallImmediate_006fdd00(lua_State* L);
// src: EXE [0x00a5b114]
extern const char g_str_CallImmediate_00a5b114[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5b124]
extern const char g_str_Count_00a5b124[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5b12c]
extern const char g_str_Dispatch_00a5b12c[];
// src: GUESS (confidence: high) [0x0049eba0]
int l_Remove_0049eba0(lua_State* L);
// src: EXE [0x00a5b138]
extern const char g_str_Remove_00a5b138[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5b140]
extern const char g_str_RemoveAll_00a5b140[];

void RegisterEventMethods_00782a40(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00662bd0, 1);
    lua_setfield(L, -3, g_str_Add_00a5b108);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0045e070, 1);
    lua_setfield(L, -3, g_str_Call_00a5b10c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_006fdd00, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5b114);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5b124);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5b12c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_0049eba0, 1);
    lua_setfield(L, -3, g_str_Remove_00a5b138);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5b140);
}
