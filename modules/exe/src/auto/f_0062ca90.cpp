// src: GUESS (confidence: high) [0x0062ca90]
// c5d-cflags: -/GF
#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006c6420]
int __cdecl Lua_MetaGc_006c6420(lua_State* L);
// src: GUESS (confidence: low) [0x004ffaf0]
int __cdecl Lua_MetaGetValue_004ffaf0(lua_State* L);
// src: GUESS (confidence: low) [0x0074f7b0]
int __cdecl Lua_MetaSetValue_0074f7b0(lua_State* L);
// src: GUESS (confidence: low) [0x0053c660]
int __cdecl Lua_MetaQuery_0053c660(lua_State* L);

// src: EXE [0x00a6c5dc]
extern const char g_str_gc_00a6c5dc[];
// src: EXE [0x00a6c5e4]
extern const char g_str_index_00a6c5e4[];
// src: EXE [0x00a6c5ec]
extern const char g_str_GetValue_00a6c5ec[];
// src: EXE [0x00a6c5f8]
extern const char g_str_SetValue_00a6c5f8[];
// src: EXE [0x00a6c604]
extern const char g_str_Query_00a6c604[];
// src: EXE [0x00a6c60c]
extern const char g_str_newindex_00a6c60c[];

// src: GUESS (confidence: high) [0x0062ca90]
void Lua_InitMetatable_0062ca90(lua_State* L, int idx) {
    lua_createtable(L, 0, 0);
    int iMeta = idx + 1;

    lua_pushstring(L, g_str_gc_00a6c5dc);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaGc_006c6420, 1);
    lua_rawset(L, iMeta);

    lua_pushstring(L, g_str_index_00a6c5e4);
    lua_createtable(L, 0, 0);
    int iMethods = iMeta + 2;

    lua_pushstring(L, g_str_GetValue_00a6c5ec);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaGetValue_004ffaf0, 1);
    lua_rawset(L, iMethods);

    lua_pushstring(L, g_str_SetValue_00a6c5f8);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaSetValue_0074f7b0, 1);
    lua_rawset(L, iMethods);

    lua_pushstring(L, g_str_Query_00a6c604);
    lua_pushvalue(L, idx);
    lua_pushcclosure(L, Lua_MetaQuery_0053c660, 1);
    lua_rawset(L, iMethods);

    lua_pushstring(L, g_str_newindex_00a6c60c);
    lua_pushvalue(L, iMethods);
    lua_rawset(L, iMeta);

    lua_rawset(L, iMeta);
    lua_setmetatable(L, idx);
}
