// c5d-model: Gemini 4 Hydrogen
struct lua_State;
typedef int (__cdecl *lua_CFunction)(lua_State* L);

extern "C" {
    void __cdecl luaL_openlibs(lua_State* L);
    void __cdecl lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
    void __cdecl lua_setfield(lua_State* L, int idx, const char* k);
    void __cdecl lua_getfield(lua_State* L, int idx, const char* k);
    void __cdecl lua_settop(lua_State* L, int idx);
    void __cdecl lua_createtable(lua_State* L, int narr, int nrec);
    void __cdecl lua_pushvalue(lua_State* L, int idx);
    void __cdecl lua_pushlstring(lua_State* L, const char* s, unsigned int len);
    int  __cdecl lua_setmetatable(lua_State* L, int objindex);
}

#define LUA_GLOBALSINDEX (-10002)

// src: EXE [0x005493f0]
int __cdecl l_GetLuaMemoryUsage(lua_State* L);
// src: EXE [0x0063df20]
int __cdecl l_CollectLuaMemoryUsage(lua_State* L);
// src: EXE [0x00658fd0]
int __cdecl l_GetSystemMemoryUsage(lua_State* L);
// src: EXE [0x0075f5f0]
int __cdecl l_CollectSystemMemoryUsage(lua_State* L);
// src: EXE [0x0062e670]
int __cdecl l_GetDllContextMemoryUsage(lua_State* L);
// src: EXE [0x0045caf0]
int __cdecl l_CollectDllContextMemoryUsage(lua_State* L);
// src: EXE [0x005221f0]
int __cdecl l_clamp(lua_State* L);
// src: EXE [0x004aac00]
int __cdecl l_count(lua_State* L);
// src: EXE [0x0066df70]
int __cdecl l_fill(lua_State* L);
// src: EXE [0x0068c110]
int __cdecl l_print(lua_State* L);
// src: EXE [0x0074c920]
int __cdecl l_ipairs_aux(lua_State* L);
// src: EXE [0x0048da50]
int __cdecl l_ipairs(lua_State* L);
// src: EXE [0x0068f3d0]
int __cdecl l_where(lua_State* L);
// src: EXE [0x006ab1e0]
int __cdecl l_CreateThread(lua_State* L);
// src: EXE [0x005a49d0]
int __cdecl l_DestroyThread(lua_State* L);

// src: GUESS (confidence: high) [0x007a5b30]
int __cdecl InitLuaGlobals_007a5b30(lua_State* L) {
    luaL_openlibs(L);
    lua_pushcclosure(L, l_GetLuaMemoryUsage, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "GetLuaMemoryUsage");
    lua_pushcclosure(L, l_CollectLuaMemoryUsage, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "CollectLuaMemoryUsage");
    lua_pushcclosure(L, l_GetSystemMemoryUsage, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "GetSystemMemoryUsage");
    lua_pushcclosure(L, l_CollectSystemMemoryUsage, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "CollectSystemMemoryUsage");
    lua_pushcclosure(L, l_GetDllContextMemoryUsage, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "GetDllContextMemoryUsage");
    lua_pushcclosure(L, l_CollectDllContextMemoryUsage, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "CollectDllContextMemoryUsage");

    lua_getfield(L, LUA_GLOBALSINDEX, "math");
    lua_pushcclosure(L, l_clamp, 0);
    lua_setfield(L, -2, "clamp");
    lua_settop(L, -2);

    lua_getfield(L, LUA_GLOBALSINDEX, "table");
    lua_pushcclosure(L, l_count, 0);
    lua_setfield(L, -2, "count");
    lua_pushcclosure(L, l_fill, 0);
    lua_setfield(L, -2, "fill");
    lua_settop(L, -2);

    lua_pushcclosure(L, l_print, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "print");
    lua_pushcclosure(L, l_ipairs_aux, 0);
    lua_pushcclosure(L, l_ipairs, 1);
    lua_setfield(L, LUA_GLOBALSINDEX, "ipairs");
    lua_pushcclosure(L, l_where, 0);
    lua_setfield(L, LUA_GLOBALSINDEX, "where");

    lua_createtable(L, 0, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_GLOBALSINDEX, "Threads");
    lua_pushvalue(L, -1);
    lua_createtable(L, 0, 0);
    lua_pushvalue(L, -1);
    lua_createtable(L, 0, 0);
    lua_pushlstring(L, "k", 1);
    lua_setfield(L, -2, "__mode\0");
    lua_setmetatable(L, -2);
    lua_setfield(L, LUA_GLOBALSINDEX, "WeakThreads");
    lua_pushcclosure(L, l_CreateThread, 2);
    lua_setfield(L, LUA_GLOBALSINDEX, "_CreateThread");
    lua_pushcclosure(L, l_DestroyThread, 1);
    lua_setfield(L, LUA_GLOBALSINDEX, "_DestroyThread");
    return 0;
}
