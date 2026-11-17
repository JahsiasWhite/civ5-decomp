// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00409610]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00668180]
int l_Add_00668180(lua_State* L);
// src: EXE [0x00a58eec]
extern const char g_str_Add_00a58eec[];
// src: GUESS (confidence: high) [0x004e2460]
int l_Call_004e2460(lua_State* L);
// src: EXE [0x00a58ef0]
extern const char g_str_Call_00a58ef0[];
// src: GUESS (confidence: high) [0x00447070]
int l_CallImmediate_00447070(lua_State* L);
// src: EXE [0x00a58ef8]
extern const char g_str_CallImmediate_00a58ef8[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a58f08]
extern const char g_str_Count_00a58f08[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a58f10]
extern const char g_str_Dispatch_00a58f10[];
// src: GUESS (confidence: high) [0x0068f8b0]
int l_Remove_0068f8b0(lua_State* L);
// src: EXE [0x00a58f1c]
extern const char g_str_Remove_00a58f1c[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a58f24]
extern const char g_str_RemoveAll_00a58f24[];

void RegisterEventMethods_00409610(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00668180, 1);
    lua_setfield(L, -3, g_str_Add_00a58eec);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_004e2460, 1);
    lua_setfield(L, -3, g_str_Call_00a58ef0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00447070, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a58ef8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a58f08);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a58f10);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_0068f8b0, 1);
    lua_setfield(L, -3, g_str_Remove_00a58f1c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a58f24);
}
