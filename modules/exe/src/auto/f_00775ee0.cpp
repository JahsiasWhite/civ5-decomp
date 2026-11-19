// src: GUESS (confidence: high) [0x006d4010]
#include "LuaApi.h"

// src: GUESS (confidence: low) [0x007498b0]
int __cdecl Lua_ProfilerReportSamples_007498b0(lua_State* L);
// src: GUESS (confidence: low) [0x006b1ff0]
int __cdecl Lua_ProfilerReportFPS_006b1ff0(lua_State* L);
// src: GUESS (confidence: low) [0x0062bca0]
int __cdecl Lua_ProfilerBeginTiming_0062bca0(lua_State* L);
// src: GUESS (confidence: low) [0x00578df0]
int __cdecl Lua_ProfilerAssert_00578df0(lua_State* L);
// src: GUESS (confidence: low) [0x006cd530]
int __cdecl Lua_ProfilerGetEngineInfoRowString_006cd530(lua_State* L);

// src: EXE [0x00a6f46c]
extern const char g_str_Profiler_00a6f46c[];
// src: EXE [0x00a6f478]
extern const char g_str_ReportSamples_00a6f478[];
// src: EXE [0x00a6f488]
extern const char g_str_ReportFPS_00a6f488[];
// src: EXE [0x00a6f494]
extern const char g_str_BeginTiming_00a6f494[];
// src: EXE [0x00a6f4a0]
extern const char g_str_Assert_00a6f4a0[];
// src: EXE [0x00a6f4a8]
extern const char g_str_GetEngineInfoRowString_00a6f4a8[];

// src: GUESS (confidence: high) [0x006d4010]
int Lua_RegisterProfiler_006d4010(lua_State* L) {
    lua_createtable(L, 0, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_GLOBALSINDEX, g_str_Profiler_00a6f46c);

    lua_pushcclosure(L, Lua_ProfilerReportSamples_007498b0, 0);
    lua_setfield(L, -2, g_str_ReportSamples_00a6f478);

    lua_pushcclosure(L, Lua_ProfilerReportFPS_006b1ff0, 0);
    lua_setfield(L, -2, g_str_ReportFPS_00a6f488);

    lua_pushcclosure(L, Lua_ProfilerBeginTiming_0062bca0, 0);
    lua_setfield(L, -2, g_str_BeginTiming_00a6f494);

    lua_pushcclosure(L, Lua_ProfilerAssert_00578df0, 0);
    lua_setfield(L, -2, g_str_Assert_00a6f4a0);

    lua_pushcclosure(L, Lua_ProfilerGetEngineInfoRowString_006cd530, 0);
    lua_setfield(L, -2, g_str_GetEngineInfoRowString_00a6f4a8);

    return 0;
}
