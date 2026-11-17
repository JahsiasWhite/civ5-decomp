// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006daa40]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x005a5ce0]
int l_Add_005a5ce0(lua_State* L);
// src: EXE [0x00a58c9c]
extern const char g_str_Add_00a58c9c[];
// src: GUESS (confidence: high) [0x0068e8e0]
int l_Call_0068e8e0(lua_State* L);
// src: EXE [0x00a58ca0]
extern const char g_str_Call_00a58ca0[];
// src: GUESS (confidence: high) [0x00441250]
int l_CallImmediate_00441250(lua_State* L);
// src: EXE [0x00a58ca8]
extern const char g_str_CallImmediate_00a58ca8[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a58cb8]
extern const char g_str_Count_00a58cb8[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a58cc0]
extern const char g_str_Dispatch_00a58cc0[];
// src: GUESS (confidence: high) [0x006e08b0]
int l_Remove_006e08b0(lua_State* L);
// src: EXE [0x00a58ccc]
extern const char g_str_Remove_00a58ccc[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a58cd4]
extern const char g_str_RemoveAll_00a58cd4[];

void RegisterEventMethods_006daa40(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_005a5ce0, 1);
    lua_setfield(L, -3, g_str_Add_00a58c9c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0068e8e0, 1);
    lua_setfield(L, -3, g_str_Call_00a58ca0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00441250, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a58ca8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a58cb8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a58cc0);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_006e08b0, 1);
    lua_setfield(L, -3, g_str_Remove_00a58ccc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a58cd4);
}
