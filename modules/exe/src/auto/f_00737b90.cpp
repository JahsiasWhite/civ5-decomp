// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00737b90]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x004b2400]
int l_Add_004b2400(lua_State* L);
// src: EXE [0x00a5a328]
extern const char g_str_Add_00a5a328[];
// src: GUESS (confidence: high) [0x00472220]
int l_Call_00472220(lua_State* L);
// src: EXE [0x00a5a32c]
extern const char g_str_Call_00a5a32c[];
// src: GUESS (confidence: high) [0x0050e8e0]
int l_CallImmediate_0050e8e0(lua_State* L);
// src: EXE [0x00a5a334]
extern const char g_str_CallImmediate_00a5a334[];
// src: GUESS (confidence: high) [0x0076c520]
int l_Count_0076c520(lua_State* L);
// src: EXE [0x00a5a344]
extern const char g_str_Count_00a5a344[];
// src: GUESS (confidence: high) [0x00558a90]
int l_Dispatch_00558a90(lua_State* L);
// src: EXE [0x00a5a34c]
extern const char g_str_Dispatch_00a5a34c[];
// src: GUESS (confidence: high) [0x00787200]
int l_Remove_00787200(lua_State* L);
// src: EXE [0x00a5a358]
extern const char g_str_Remove_00a5a358[];
// src: GUESS (confidence: high) [0x005c2ec0]
int l_RemoveAll_005c2ec0(lua_State* L);
// src: EXE [0x00a5a360]
extern const char g_str_RemoveAll_00a5a360[];

void RegisterEventMethods_00737b90(lua_State* L) {
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Add_004b2400, 1);
    lua_setfield(L, -3, g_str_Add_00a5a328);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Call_00472220, 1);
    lua_setfield(L, -3, g_str_Call_00a5a32c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_CallImmediate_0050e8e0, 1);
    lua_setfield(L, -3, g_str_CallImmediate_00a5a334);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Count_0076c520, 1);
    lua_setfield(L, -3, g_str_Count_00a5a344);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Dispatch_00558a90, 1);
    lua_setfield(L, -3, g_str_Dispatch_00a5a34c);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_Remove_00787200, 1);
    lua_setfield(L, -3, g_str_Remove_00a5a358);
    lua_pushvalue(L, -1);
    lua_pushcclosure(L, l_RemoveAll_005c2ec0, 1);
    lua_setfield(L, -3, g_str_RemoveAll_00a5a360);
}
