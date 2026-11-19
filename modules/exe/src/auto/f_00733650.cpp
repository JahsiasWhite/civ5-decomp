// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0070d890]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0070d890 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x007185b0]
void PushFn_007185b0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x0062b630]
int l_GC_0062b630(lua_State* L);
// src: EXE [0x00a58ec4]
extern const char g_str_ct_00a58ec4[];
// src: EXE [0x00a58ed4]
extern const char g_str_eh_00a58ed4[];
// src: EXE [0x00a58ee4]
extern const char g_str_gc_00a58ee4[];

void SetupCallbackThread_0070d890(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a58ec4);
    lua_State* co = lua_newthread(L);
    PushFn_007185b0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a58ed4);
    EventHandle_0070d890* h = (EventHandle_0070d890*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a58ee4);
    lua_pushcclosure(L, l_GC_0062b630, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
