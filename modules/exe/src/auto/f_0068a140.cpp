// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0068a140]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0053c5e0]
int l_Add_0053c5e0(lua_State* L);
// src: EXE [0x00a5d040]
extern const char g_str_Add_00a5d040[];
// src: GUESS (confidence: high) [0x0051f910]
int l_Call_0051f910(lua_State* L);
// src: EXE [0x00a5d044]
extern const char g_str_Call_00a5d044[];
// src: GUESS (confidence: high) [0x006a16c0]
int l_CallImmediate_006a16c0(lua_State* L);
// src: EXE [0x00a5d04c]
extern const char g_str_CallImmediate_00a5d04c[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5d05c]
extern const char g_str_Count_00a5d05c[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5d064]
extern const char g_str_Dispatch_00a5d064[];
// src: GUESS (confidence: high) [0x004d7670]
int l_Remove_004d7670(lua_State* L);
// src: EXE [0x00a5d070]
extern const char g_str_Remove_00a5d070[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5d078]
extern const char g_str_RemoveAll_00a5d078[];

void RegisterEventMethods_0068a140(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_0053c5e0, 1);
    lua_setfield(L, -3, g_str_Add_00a5d040);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0051f910, 1);
    lua_setfield(L, -3, g_str_Call_00a5d044);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_006a16c0, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5d04c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5d05c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5d064);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_004d7670, 1);
    lua_setfield(L, -3, g_str_Remove_00a5d070);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5d078);
}
