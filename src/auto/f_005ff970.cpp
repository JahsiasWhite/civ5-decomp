// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x005ff970]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x005aa650]
int l_Add_005aa650(lua_State* L);
// src: EXE [0x00a5a450]
extern const char g_str_Add_00a5a450[];
// src: GUESS (confidence: high) [0x005fbc60]
int l_Call_005fbc60(lua_State* L);
// src: EXE [0x00a5a454]
extern const char g_str_Call_00a5a454[];
// src: GUESS (confidence: high) [0x0075e340]
int l_CallImmediate_0075e340(lua_State* L);
// src: EXE [0x00a5a45c]
extern const char g_str_CallImmediate_00a5a45c[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5a46c]
extern const char g_str_Count_00a5a46c[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5a474]
extern const char g_str_Dispatch_00a5a474[];
// src: GUESS (confidence: high) [0x007adc40]
int l_Remove_007adc40(lua_State* L);
// src: EXE [0x00a5a480]
extern const char g_str_Remove_00a5a480[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5a488]
extern const char g_str_RemoveAll_00a5a488[];

void RegisterEventMethods_005ff970(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_005aa650, 1);
    lua_setfield(L, -3, g_str_Add_00a5a450);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_005fbc60, 1);
    lua_setfield(L, -3, g_str_Call_00a5a454);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_0075e340, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5a45c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5a46c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5a474);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_007adc40, 1);
    lua_setfield(L, -3, g_str_Remove_00a5a480);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5a488);
}
