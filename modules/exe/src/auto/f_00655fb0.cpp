// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00655fb0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x0063f9c0]
int l_Add_0063f9c0(lua_State* L);
// src: EXE [0x00a5a200]
extern const char g_str_Add_00a5a200[];
// src: GUESS (confidence: high) [0x005cce30]
int l_Call_005cce30(lua_State* L);
// src: EXE [0x00a5a204]
extern const char g_str_Call_00a5a204[];
// src: GUESS (confidence: high) [0x00545d70]
int l_CallImmediate_00545d70(lua_State* L);
// src: EXE [0x00a5a20c]
extern const char g_str_CallImmediate_00a5a20c[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5a21c]
extern const char g_str_Count_00a5a21c[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5a224]
extern const char g_str_Dispatch_00a5a224[];
// src: GUESS (confidence: high) [0x005b6a00]
int l_Remove_005b6a00(lua_State* L);
// src: EXE [0x00a5a230]
extern const char g_str_Remove_00a5a230[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5a238]
extern const char g_str_RemoveAll_00a5a238[];

void RegisterEventMethods_00655fb0(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_0063f9c0, 1);
    lua_setfield(L, -3, g_str_Add_00a5a200);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_005cce30, 1);
    lua_setfield(L, -3, g_str_Call_00a5a204);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00545d70, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5a20c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5a21c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5a224);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_005b6a00, 1);
    lua_setfield(L, -3, g_str_Remove_00a5a230);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5a238);
}
