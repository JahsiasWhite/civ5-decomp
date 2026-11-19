// src: GUESS (confidence: high) [0x0068e7d0]
// c5d-cflags: -/GF
#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006c6420]
int __cdecl Lua_MetaGc_006c6420(lua_State* L);
// src: GUESS (confidence: low) [0x0078a780]
int __cdecl Lua_MetaGetValue_0078a780(lua_State* L);
// src: GUESS (confidence: low) [0x0044bb50]
int __cdecl Lua_MetaSetValue_0044bb50(lua_State* L);
// src: GUESS (confidence: low) [0x007b6190]
int __cdecl Lua_MetaQuery_007b6190(lua_State* L);

// src: EXE [0x00a6c230]
extern const char g_str_gc_00a6c230[];
// src: EXE [0x00a6c238]
extern const char g_str_index_00a6c238[];
// src: EXE [0x00a6c240]
extern const char g_str_GetValue_00a6c240[];
// src: EXE [0x00a6c24c]
extern const char g_str_SetValue_00a6c24c[];
// src: EXE [0x00a6c258]
extern const char g_str_Query_00a6c258[];
// src: EXE [0x00a6c260]
extern const char g_str_newindex_00a6c260[];

// src: GUESS (confidence: high) [0x0068e7d0]
void Lua_InitMetatable_0068e7d0(lua_State* L, int idx) {
    lua_createtable(L, 0, 0);
    int iMeta = idx + 1;

    lua_pushstring(L, g_str_gc_00a6c230);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaGc_006c6420, 1);
    lua_rawset(L, iMeta);

    lua_pushstring(L, g_str_index_00a6c238);
    lua_createtable(L, 0, 0);
    int iMethods = iMeta + 2;

    lua_pushstring(L, g_str_GetValue_00a6c240);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaGetValue_0078a780, 1);
    lua_rawset(L, iMethods);

    lua_pushstring(L, g_str_SetValue_00a6c24c);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaSetValue_0044bb50, 1);
    lua_rawset(L, iMethods);

    lua_pushstring(L, g_str_Query_00a6c258);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaQuery_007b6190, 1);
    lua_rawset(L, iMethods);

    lua_pushstring(L, g_str_newindex_00a6c260);
    lua_pushvalue(L, iMethods);
    lua_rawset(L, iMeta);

    lua_rawset(L, iMeta);
    lua_setmetatable(L, idx);
}
