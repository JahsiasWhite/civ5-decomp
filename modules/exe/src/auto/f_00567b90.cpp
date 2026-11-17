// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00567b90]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00774f60]
int l_Add_00774f60(lua_State* L);
// src: EXE [0x00a615a0]
extern const char g_str_Add_00a615a0[];
// src: GUESS (confidence: high) [0x004d5c00]
int l_Call_004d5c00(lua_State* L);
// src: EXE [0x00a615a4]
extern const char g_str_Call_00a615a4[];
// src: GUESS (confidence: high) [0x004628f0]
int l_CallImmediate_004628f0(lua_State* L);
// src: EXE [0x00a615ac]
extern const char g_str_CallImmediate_00a615ac[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a615bc]
extern const char g_str_Count_00a615bc[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a615c4]
extern const char g_str_Dispatch_00a615c4[];
// src: GUESS (confidence: high) [0x006b8a60]
int l_Remove_006b8a60(lua_State* L);
// src: EXE [0x00a615d0]
extern const char g_str_Remove_00a615d0[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a615d8]
extern const char g_str_RemoveAll_00a615d8[];

void RegisterEventMethods_00567b90(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00774f60, 1);
    lua_setfield(L, -3, g_str_Add_00a615a0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_004d5c00, 1);
    lua_setfield(L, -3, g_str_Call_00a615a4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_004628f0, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a615ac);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a615bc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a615c4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_006b8a60, 1);
    lua_setfield(L, -3, g_str_Remove_00a615d0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a615d8);
}
