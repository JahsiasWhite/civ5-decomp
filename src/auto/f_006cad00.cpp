// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006cad00]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x004867b0]
int l_Add_004867b0(lua_State* L);
// src: EXE [0x00a5e638]
extern const char g_str_Add_00a5e638[];
// src: GUESS (confidence: high) [0x0053bf80]
int l_Call_0053bf80(lua_State* L);
// src: EXE [0x00a5e63c]
extern const char g_str_Call_00a5e63c[];
// src: GUESS (confidence: high) [0x00443b50]
int l_CallImmediate_00443b50(lua_State* L);
// src: EXE [0x00a5e644]
extern const char g_str_CallImmediate_00a5e644[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5e654]
extern const char g_str_Count_00a5e654[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5e65c]
extern const char g_str_Dispatch_00a5e65c[];
// src: GUESS (confidence: high) [0x005b1c10]
int l_Remove_005b1c10(lua_State* L);
// src: EXE [0x00a5e668]
extern const char g_str_Remove_00a5e668[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5e670]
extern const char g_str_RemoveAll_00a5e670[];

void RegisterEventMethods_006cad00(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_004867b0, 1);
    lua_setfield(L, -3, g_str_Add_00a5e638);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_0053bf80, 1);
    lua_setfield(L, -3, g_str_Call_00a5e63c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00443b50, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5e644);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5e654);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5e65c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_005b1c10, 1);
    lua_setfield(L, -3, g_str_Remove_00a5e668);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5e670);
}
