// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x005156c0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006290c0]
int l_Add_006290c0(lua_State* L);
// src: EXE [0x00a5bc04]
extern const char g_str_Add_00a5bc04[];
// src: GUESS (confidence: high) [0x0051d780]
int l_Call_0051d780(lua_State* L);
// src: EXE [0x00a5bc08]
extern const char g_str_Call_00a5bc08[];
// src: GUESS (confidence: high) [0x0045ea40]
int l_CallImmediate_0045ea40(lua_State* L);
// src: EXE [0x00a5bc10]
extern const char g_str_CallImmediate_00a5bc10[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5bc20]
extern const char g_str_Count_00a5bc20[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5bc28]
extern const char g_str_Dispatch_00a5bc28[];
// src: GUESS (confidence: high) [0x00704900]
int l_Remove_00704900(lua_State* L);
// src: EXE [0x00a5bc34]
extern const char g_str_Remove_00a5bc34[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5bc3c]
extern const char g_str_RemoveAll_00a5bc3c[];

void RegisterEventMethods_005156c0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_006290c0, 1);
    lua_setfield(L, -3, g_str_Add_00a5bc04);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0051d780, 1);
    lua_setfield(L, -3, g_str_Call_00a5bc08);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_0045ea40, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5bc10);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5bc20);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5bc28);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00704900, 1);
    lua_setfield(L, -3, g_str_Remove_00a5bc34);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5bc3c);
}
