// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0058b040]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x004a2140]
int l_IsEnabled_004a2140(lua_State* L);
// src: EXE [0x00a6a370]
extern const char g_str_IsEnabled_00a6a370[];
// src: GUESS (confidence: high) [0x00447b70]
int l_Enable_00447b70(lua_State* L);
// src: EXE [0x00a6a37c]
extern const char g_str_Enable_00a6a37c[];
// src: GUESS (confidence: high) [0x00462e60]
int l_IncrementMarker_00462e60(lua_State* L);
// src: EXE [0x00a6a384]
extern const char g_str_IncrementMarker_00a6a384[];
// src: GUESS (confidence: high) [0x007239b0]
int l_DumpAllocations_007239b0(lua_State* L);
// src: EXE [0x00a6a394]
extern const char g_str_DumpAllocations_00a6a394[];
// src: GUESS (confidence: high) [0x00717f00]
int l_Report_00717f00(lua_State* L);
// src: EXE [0x00a6a3a4]
extern const char g_str_Report_00a6a3a4[];
// src: GUESS (confidence: high) [0x005aa130]
int l_DumpLuaAllocations_005aa130(lua_State* L);
// src: EXE [0x00a6a3ac]
extern const char g_str_DumpLuaAllocations_00a6a3ac[];

int RegisterMemoryTrackerLib_0058b040(lua_State* L) {
    lua_createtable(L, 0, 0);
    lua_pushcclosure(L, l_IsEnabled_004a2140, 0);
    lua_setfield(L, -2, g_str_IsEnabled_00a6a370);
    lua_pushcclosure(L, l_Enable_00447b70, 0);
    lua_setfield(L, -2, g_str_Enable_00a6a37c);
    lua_pushcclosure(L, l_IncrementMarker_00462e60, 0);
    lua_setfield(L, -2, g_str_IncrementMarker_00a6a384);
    lua_pushcclosure(L, l_DumpAllocations_007239b0, 0);
    lua_setfield(L, -2, g_str_DumpAllocations_00a6a394);
    lua_pushcclosure(L, l_Report_00717f00, 0);
    lua_setfield(L, -2, g_str_Report_00a6a3a4);
    lua_pushcclosure(L, l_DumpLuaAllocations_005aa130, 0);
    lua_setfield(L, -2, g_str_DumpLuaAllocations_00a6a3ac);
    return 1;
}
