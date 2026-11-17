// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00585b20]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00423070]
int l_Add_00423070(lua_State* L);
// src: EXE [0x00a5a60c]
extern const char g_str_Add_00a5a60c[];
// src: GUESS (confidence: high) [0x007376f0]
int l_Call_007376f0(lua_State* L);
// src: EXE [0x00a5a610]
extern const char g_str_Call_00a5a610[];
// src: GUESS (confidence: high) [0x00799780]
int l_CallImmediate_00799780(lua_State* L);
// src: EXE [0x00a5a618]
extern const char g_str_CallImmediate_00a5a618[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5a628]
extern const char g_str_Count_00a5a628[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5a630]
extern const char g_str_Dispatch_00a5a630[];
// src: GUESS (confidence: high) [0x00543040]
int l_Remove_00543040(lua_State* L);
// src: EXE [0x00a5a63c]
extern const char g_str_Remove_00a5a63c[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5a644]
extern const char g_str_RemoveAll_00a5a644[];

void RegisterEventMethods_00585b20(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_00423070, 1);
    lua_setfield(L, -3, g_str_Add_00a5a60c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_007376f0, 1);
    lua_setfield(L, -3, g_str_Call_00a5a610);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_00799780, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5a618);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5a628);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5a630);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00543040, 1);
    lua_setfield(L, -3, g_str_Remove_00a5a63c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5a644);
}
