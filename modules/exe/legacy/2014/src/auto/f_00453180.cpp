// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00453180]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x006cfef0]
int l_Add_006cfef0(lua_State* L);
// src: EXE [0x00a5b5a8]
extern const char g_str_Add_00a5b5a8[];
// src: GUESS (confidence: high) [0x005c63b0]
int l_Call_005c63b0(lua_State* L);
// src: EXE [0x00a5b5ac]
extern const char g_str_Call_00a5b5ac[];
// src: GUESS (confidence: high) [0x004018e0]
int l_CallImmediate_004018e0(lua_State* L);
// src: EXE [0x00a5b5b4]
extern const char g_str_CallImmediate_00a5b5b4[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5b5c4]
extern const char g_str_Count_00a5b5c4[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5b5cc]
extern const char g_str_Dispatch_00a5b5cc[];
// src: GUESS (confidence: high) [0x0069cb30]
int l_Remove_0069cb30(lua_State* L);
// src: EXE [0x00a5b5d8]
extern const char g_str_Remove_00a5b5d8[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5b5e0]
extern const char g_str_RemoveAll_00a5b5e0[];

void RegisterEventMethods_00453180(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_006cfef0, 1);
    lua_setfield(L, -3, g_str_Add_00a5b5a8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_005c63b0, 1);
    lua_setfield(L, -3, g_str_Call_00a5b5ac);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_004018e0, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5b5b4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5b5c4);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5b5cc);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_0069cb30, 1);
    lua_setfield(L, -3, g_str_Remove_00a5b5d8);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5b5e0);
}
