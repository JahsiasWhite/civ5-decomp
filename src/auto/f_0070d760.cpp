// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0070d760]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0070d760 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x00782f80]
void PushFn_00782f80(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006c7bb0]
int l_GC_006c7bb0(lua_State* L);
// src: EXE [0x00a5c894]
extern const char g_str_ct_00a5c894[];
// src: EXE [0x00a5c8a4]
extern const char g_str_eh_00a5c8a4[];
// src: EXE [0x00a5c8b4]
extern const char g_str_gc_00a5c8b4[];

void SetupCallbackThread_0070d760(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5c894);
    lua_State* co = lua_newthread(L);
    PushFn_00782f80(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5c8a4);
    EventHandle_0070d760* h = (EventHandle_0070d760*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5c8b4);
    lua_pushcclosure(L, l_GC_006c7bb0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
