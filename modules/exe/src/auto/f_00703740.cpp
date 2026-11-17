// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00703740]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00616050]
int l_Add_00616050(lua_State* L);
// src: EXE [0x00a5ee50]
extern const char g_str_Add_00a5ee50[];
// src: GUESS (confidence: high) [0x005db5a0]
int l_Call_005db5a0(lua_State* L);
// src: EXE [0x00a5ee54]
extern const char g_str_Call_00a5ee54[];
// src: GUESS (confidence: high) [0x00798140]
int l_CallImmediate_00798140(lua_State* L);
// src: EXE [0x00a5ee5c]
extern const char g_str_CallImmediate_00a5ee5c[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5ee6c]
extern const char g_str_Count_00a5ee6c[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5ee74]
extern const char g_str_Dispatch_00a5ee74[];
// src: GUESS (confidence: high) [0x007b1880]
int l_Remove_007b1880(lua_State* L);
// src: EXE [0x00a5ee80]
extern const char g_str_Remove_00a5ee80[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5ee88]
extern const char g_str_RemoveAll_00a5ee88[];

void RegisterEventMethods_00703740(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00616050, 1);
    lua_setfield(L, -3, g_str_Add_00a5ee50);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_005db5a0, 1);
    lua_setfield(L, -3, g_str_Call_00a5ee54);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00798140, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5ee5c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5ee6c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5ee74);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_007b1880, 1);
    lua_setfield(L, -3, g_str_Remove_00a5ee80);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5ee88);
}
