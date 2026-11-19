// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x005432f0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0055d000]
int l_Add_0055d000(lua_State* L);
// src: EXE [0x00a60a10]
extern const char g_str_Add_00a60a10[];
// src: GUESS (confidence: high) [0x0041cf60]
int l_Call_0041cf60(lua_State* L);
// src: EXE [0x00a60a14]
extern const char g_str_Call_00a60a14[];
// src: GUESS (confidence: high) [0x004c4980]
int l_CallImmediate_004c4980(lua_State* L);
// src: EXE [0x00a60a1c]
extern const char g_str_CallImmediate_00a60a1c[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a60a2c]
extern const char g_str_Count_00a60a2c[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a60a34]
extern const char g_str_Dispatch_00a60a34[];
// src: GUESS (confidence: high) [0x00654830]
int l_Remove_00654830(lua_State* L);
// src: EXE [0x00a60a40]
extern const char g_str_Remove_00a60a40[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a60a48]
extern const char g_str_RemoveAll_00a60a48[];

void RegisterEventMethods_005432f0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_0055d000, 1);
    lua_setfield(L, -3, g_str_Add_00a60a10);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0041cf60, 1);
    lua_setfield(L, -3, g_str_Call_00a60a14);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_004c4980, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a60a1c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a60a2c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a60a34);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00654830, 1);
    lua_setfield(L, -3, g_str_Remove_00a60a40);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a60a48);
}
