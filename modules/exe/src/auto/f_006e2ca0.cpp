// src: GUESS (confidence: high) [0x006db0e0]
#include "LuaApi.h"

// src: GUESS (confidence: low) [0x005d2f80]
int __cdecl Lua_AutoSetGameCoreInit_005d2f80(lua_State* L);
// src: GUESS (confidence: low) [0x0075eb40]
int __cdecl Lua_AutoSetEventScript_0075eb40(lua_State* L);
// src: GUESS (confidence: low) [0x004a8d60]
int __cdecl Lua_AutoSetEventFunction_004a8d60(lua_State* L);
// src: GUESS (confidence: low) [0x0072c330]
int __cdecl Lua_AutoGetAutorunTurnLimit_0072c330(lua_State* L);
// src: EXE [0x00620720]
int __cdecl l_ExitGame(lua_State* L);
// src: GUESS (confidence: low) [0x00750240]
int __cdecl Lua_AutoIsExitingGame_00750240(lua_State* L);

// src: EXE [0x00a569e4]
extern const char g_str_Automation_00a569e4[];
// src: EXE [0x00a56b1c]
extern const char g_str_SetGameCoreInit_00a56b1c[];
// src: EXE [0x00a56b2c]
extern const char g_str_SetEventScript_00a56b2c[];
// src: EXE [0x00a56b3c]
extern const char g_str_SetEventFunction_00a56b3c[];
// src: EXE [0x00a56b50]
extern const char g_str_GetAutorunTurnLimit_00a56b50[];
// src: EXE [0x00a56b64]
extern const char g_str_ExitGame_00a56b64[];
// src: EXE [0x00a56b70]
extern const char g_str_IsExitingGame_00a56b70[];

// src: GUESS (confidence: high) [0x006db0e0]
int Lua_RegisterAutomation_006db0e0(lua_State* L) {
    lua_createtable(L, 0, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_GLOBALSINDEX, g_str_Automation_00a569e4);

    lua_pushcclosure(L, Lua_AutoSetGameCoreInit_005d2f80, 0);
    lua_setfield(L, -2, g_str_SetGameCoreInit_00a56b1c);

    lua_pushcclosure(L, Lua_AutoSetEventScript_0075eb40, 0);
    lua_setfield(L, -2, g_str_SetEventScript_00a56b2c);

    lua_pushcclosure(L, Lua_AutoSetEventFunction_004a8d60, 0);
    lua_setfield(L, -2, g_str_SetEventFunction_00a56b3c);

    lua_pushcclosure(L, Lua_AutoGetAutorunTurnLimit_0072c330, 0);
    lua_setfield(L, -2, g_str_GetAutorunTurnLimit_00a56b50);

    lua_pushcclosure(L, l_ExitGame, 0);
    lua_setfield(L, -2, g_str_ExitGame_00a56b64);

    lua_pushcclosure(L, Lua_AutoIsExitingGame_00750240, 0);
    lua_setfield(L, -2, g_str_IsExitingGame_00a56b70);

    return 0;
}
