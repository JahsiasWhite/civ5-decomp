// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006a0a00]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00484b50]
int l_Add_00484b50(lua_State* L);
// src: EXE [0x00a5f8b8]
extern const char g_str_Add_00a5f8b8[];
// src: GUESS (confidence: high) [0x00730b80]
int l_Call_00730b80(lua_State* L);
// src: EXE [0x00a5f8bc]
extern const char g_str_Call_00a5f8bc[];
// src: GUESS (confidence: high) [0x007a5e90]
int l_CallImmediate_007a5e90(lua_State* L);
// src: EXE [0x00a5f8c4]
extern const char g_str_CallImmediate_00a5f8c4[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5f8d4]
extern const char g_str_Count_00a5f8d4[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5f8dc]
extern const char g_str_Dispatch_00a5f8dc[];
// src: GUESS (confidence: high) [0x0062cba0]
int l_Remove_0062cba0(lua_State* L);
// src: EXE [0x00a5f8e8]
extern const char g_str_Remove_00a5f8e8[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5f8f0]
extern const char g_str_RemoveAll_00a5f8f0[];

void RegisterEventMethods_006a0a00(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00484b50, 1);
    lua_setfield(L, -3, g_str_Add_00a5f8b8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_00730b80, 1);
    lua_setfield(L, -3, g_str_Call_00a5f8bc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_007a5e90, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5f8c4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5f8d4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5f8dc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_0062cba0, 1);
    lua_setfield(L, -3, g_str_Remove_00a5f8e8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5f8f0);
}
