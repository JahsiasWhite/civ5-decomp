#include "LuaApi.h"

// src: LIB [0x00889534]
extern "C" void lua_createtable(lua_State* L, int narr, int nrec);
// src: LIB [0x0088951c]
extern "C" void lua_pushstring(lua_State* L, const char* s);
// src: LIB [0x00889522]
extern "C" void lua_rawseti(lua_State* L, int idx, int n);

// src: EXE [0x00a2dcf4]
extern const char* const g_svIconModeNames_00a2dcf4[];

// src: GUESS (confidence: medium) [0x005d58e0]
int LuaGetSVIconModes_005d58e0(lua_State* L)
{
    lua_createtable(L, 5, 0);
    for (unsigned int i = 0; i < 5; ++i) {
        lua_pushstring(L, g_svIconModeNames_00a2dcf4[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}
