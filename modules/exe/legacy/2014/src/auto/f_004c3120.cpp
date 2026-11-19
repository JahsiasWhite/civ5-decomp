// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x004c3120]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006a1390]
int l_Add_006a1390(lua_State* L);
// src: EXE [0x00a5f418]
extern const char g_str_Add_00a5f418[];
// src: GUESS (confidence: high) [0x0070dec0]
int l_Call_0070dec0(lua_State* L);
// src: EXE [0x00a5f41c]
extern const char g_str_Call_00a5f41c[];
// src: GUESS (confidence: high) [0x0053e410]
int l_CallImmediate_0053e410(lua_State* L);
// src: EXE [0x00a5f424]
extern const char g_str_CallImmediate_00a5f424[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5f434]
extern const char g_str_Count_00a5f434[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5f43c]
extern const char g_str_Dispatch_00a5f43c[];
// src: GUESS (confidence: high) [0x0052bc10]
int l_Remove_0052bc10(lua_State* L);
// src: EXE [0x00a5f448]
extern const char g_str_Remove_00a5f448[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5f450]
extern const char g_str_RemoveAll_00a5f450[];

void RegisterEventMethods_004c3120(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_006a1390, 1);
    lua_setfield(L, -3, g_str_Add_00a5f418);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0070dec0, 1);
    lua_setfield(L, -3, g_str_Call_00a5f41c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_0053e410, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5f424);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5f434);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5f43c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_0052bc10, 1);
    lua_setfield(L, -3, g_str_Remove_00a5f448);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5f450);
}
