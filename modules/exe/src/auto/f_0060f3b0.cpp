// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0060f3b0]

#include "LuaApi.h"

// src: GUESS (confidence: high) [0x005141e0]
int l_GetDirectoryName_005141e0(lua_State* L);
// src: EXE [0x00a6e888]
extern const char g_str_GetDirectoryName_00a6e888[];
// src: GUESS (confidence: high) [0x007a00f0]
int l_GetExtension_007a00f0(lua_State* L);
// src: EXE [0x00a6e89c]
extern const char g_str_GetExtension_00a6e89c[];
// src: GUESS (confidence: high) [0x006d79c0]
int l_GetFileName_006d79c0(lua_State* L);
// src: EXE [0x00a6e8ac]
extern const char g_str_GetFileName_00a6e8ac[];
// src: GUESS (confidence: high) [0x005f2080]
int l_GetFileNameWithoutExtension_005f2080(lua_State* L);
// src: EXE [0x00a6e8b8]
extern const char g_str_GetFileNameWithoutExtension_00a6e8b8[];
// src: GUESS (confidence: high) [0x00577ae0]
int l_GetAltDirectorySeparatorChar_00577ae0(lua_State* L);
// src: EXE [0x00a6e8d4]
extern const char g_str_GetAltDirectorySeparatorChar_00a6e8d4[];
// src: GUESS (confidence: high) [0x006a21f0]
int l_GetDirectorySeparatorChar_006a21f0(lua_State* L);
// src: EXE [0x00a6e8f4]
extern const char g_str_GetDirectorySeparatorChar_00a6e8f4[];
// src: GUESS (confidence: high) [0x006c9980]
int l_GetExtensionSeparatorChar_006c9980(lua_State* L);
// src: EXE [0x00a6e910]
extern const char g_str_GetExtensionSeparatorChar_00a6e910[];
// src: GUESS (confidence: high) [0x0056ebc0]
int l_GetPathSeparatorChar_0056ebc0(lua_State* L);
// src: EXE [0x00a6e92c]
extern const char g_str_GetPathSeparatorChar_00a6e92c[];
// src: GUESS (confidence: high) [0x006f8990]
int l_GetVolumeSeparatorChar_006f8990(lua_State* L);
// src: EXE [0x00a6e944]
extern const char g_str_GetVolumeSeparatorChar_00a6e944[];
// src: GUESS (confidence: high) [0x0045eaa0]
int l_NormalizePath_0045eaa0(lua_State* L);
// src: EXE [0x00a6e95c]
extern const char g_str_NormalizePath_00a6e95c[];
// src: GUESS (confidence: high) [0x00486180]
int l_UsesExtension_00486180(lua_State* L);
// src: EXE [0x00a6e96c]
extern const char g_str_UsesExtension_00a6e96c[];

int RegisterPathLib_0060f3b0(lua_State* L) {
    lua_createtable(L, 0, 5);
    lua_pushcclosure(L, l_GetDirectoryName_005141e0, 0);
    lua_setfield(L, -2, g_str_GetDirectoryName_00a6e888);
    lua_pushcclosure(L, l_GetExtension_007a00f0, 0);
    lua_setfield(L, -2, g_str_GetExtension_00a6e89c);
    lua_pushcclosure(L, l_GetFileName_006d79c0, 0);
    lua_setfield(L, -2, g_str_GetFileName_00a6e8ac);
    lua_pushcclosure(L, l_GetFileNameWithoutExtension_005f2080, 0);
    lua_setfield(L, -2, g_str_GetFileNameWithoutExtension_00a6e8b8);
    lua_pushcclosure(L, l_GetAltDirectorySeparatorChar_00577ae0, 0);
    lua_setfield(L, -2, g_str_GetAltDirectorySeparatorChar_00a6e8d4);
    lua_pushcclosure(L, l_GetDirectorySeparatorChar_006a21f0, 0);
    lua_setfield(L, -2, g_str_GetDirectorySeparatorChar_00a6e8f4);
    lua_pushcclosure(L, l_GetExtensionSeparatorChar_006c9980, 0);
    lua_setfield(L, -2, g_str_GetExtensionSeparatorChar_00a6e910);
    lua_pushcclosure(L, l_GetPathSeparatorChar_0056ebc0, 0);
    lua_setfield(L, -2, g_str_GetPathSeparatorChar_00a6e92c);
    lua_pushcclosure(L, l_GetVolumeSeparatorChar_006f8990, 0);
    lua_setfield(L, -2, g_str_GetVolumeSeparatorChar_00a6e944);
    lua_pushcclosure(L, l_NormalizePath_0045eaa0, 0);
    lua_setfield(L, -2, g_str_NormalizePath_00a6e95c);
    lua_pushcclosure(L, l_UsesExtension_00486180, 0);
    lua_setfield(L, -2, g_str_UsesExtension_00a6e96c);
    return 1;
}
