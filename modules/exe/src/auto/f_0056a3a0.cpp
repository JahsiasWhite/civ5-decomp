// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0056a3a0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x00756300]
int l_IsActive_00756300(lua_State* L);
// src: EXE [0x00a56e04]
extern const char g_str_IsActive_00a56e04[];
// src: GUESS (confidence: high) [0x00416e90]
int l_SetActive_00416e90(lua_State* L);
// src: EXE [0x00a56e10]
extern const char g_str_SetActive_00a56e10[];
// src: GUESS (confidence: high) [0x0075f360]
int l_IsInstalled_0075f360(lua_State* L);
// src: EXE [0x00a56e1c]
extern const char g_str_IsInstalled_00a56e1c[];
// src: GUESS (confidence: high) [0x00579bc0]
int l_GetAllPackageIDs_00579bc0(lua_State* L);
// src: EXE [0x00a56e28]
extern const char g_str_GetAllPackageIDs_00a56e28[];
// src: GUESS (confidence: high) [0x0057c750]
int l_GetPackageDescription_0057c750(lua_State* L);
// src: EXE [0x00a56e3c]
extern const char g_str_GetPackageDescription_00a56e3c[];
// src: GUESS (confidence: high) [0x0069b720]
int l_IsUpgrade_0069b720(lua_State* L);
// src: EXE [0x00a56e54]
extern const char g_str_IsUpgrade_00a56e54[];

int RegisterContentManagerLib_0056a3a0(lua_State* L) {
    lua_createtable(L, 0, 0);
    lua_pushcclosure(L, l_IsActive_00756300, 0);
    lua_setfield(L, -2, g_str_IsActive_00a56e04);
    lua_pushcclosure(L, l_SetActive_00416e90, 0);
    lua_setfield(L, -2, g_str_SetActive_00a56e10);
    lua_pushcclosure(L, l_IsInstalled_0075f360, 0);
    lua_setfield(L, -2, g_str_IsInstalled_00a56e1c);
    lua_pushcclosure(L, l_GetAllPackageIDs_00579bc0, 0);
    lua_setfield(L, -2, g_str_GetAllPackageIDs_00a56e28);
    lua_pushcclosure(L, l_GetPackageDescription_0057c750, 0);
    lua_setfield(L, -2, g_str_GetPackageDescription_00a56e3c);
    lua_pushcclosure(L, l_IsUpgrade_0069b720, 0);
    lua_setfield(L, -2, g_str_IsUpgrade_00a56e54);
    return 1;
}
