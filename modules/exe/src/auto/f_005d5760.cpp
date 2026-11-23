#include "LuaApi.h"

// src: LIB [0x00889534]
extern "C" void lua_createtable(lua_State* L, int narr, int nrec);
// src: LIB [0x0088951c]
extern "C" void lua_pushstring(lua_State* L, const char* s);
// src: LIB [0x00889522]
extern "C" void lua_rawseti(lua_State* L, int idx, int n);

// src: EXE [0x00a2dcac]
extern const char* const g_svOverlayNames_00a2dcac[];

// src: GUESS (confidence: medium) [0x005d5760]
int LuaGetSVOverlays_005d5760(lua_State* L)
{
    lua_createtable(L, 9, 0);
    for (unsigned int i = 0; i < 9; ++i) {
        lua_pushstring(L, g_svOverlayNames_00a2dcac[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}
