// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0079d9f0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006a69e0]
int l_Add_006a69e0(lua_State* L);
// src: EXE [0x00a5c8bc]
extern const char g_str_Add_00a5c8bc[];
// src: GUESS (confidence: high) [0x0052adb0]
int l_Call_0052adb0(lua_State* L);
// src: EXE [0x00a5c8c0]
extern const char g_str_Call_00a5c8c0[];
// src: GUESS (confidence: high) [0x004b8230]
int l_CallImmediate_004b8230(lua_State* L);
// src: EXE [0x00a5c8c8]
extern const char g_str_CallImmediate_00a5c8c8[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5c8d8]
extern const char g_str_Count_00a5c8d8[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5c8e0]
extern const char g_str_Dispatch_00a5c8e0[];
// src: GUESS (confidence: high) [0x004d4f40]
int l_Remove_004d4f40(lua_State* L);
// src: EXE [0x00a5c8ec]
extern const char g_str_Remove_00a5c8ec[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5c8f4]
extern const char g_str_RemoveAll_00a5c8f4[];

void RegisterEventMethods_0079d9f0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_006a69e0, 1);
    lua_setfield(L, -3, g_str_Add_00a5c8bc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0052adb0, 1);
    lua_setfield(L, -3, g_str_Call_00a5c8c0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_004b8230, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5c8c8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5c8d8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5c8e0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_004d4f40, 1);
    lua_setfield(L, -3, g_str_Remove_00a5c8ec);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5c8f4);
}
