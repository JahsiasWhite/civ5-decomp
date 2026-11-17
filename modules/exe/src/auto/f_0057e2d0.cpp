// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0057e2d0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0057e2d0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x006f5b80]
void PushFn_006f5b80(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00684250]
int l_GC_00684250(lua_State* L);
// src: EXE [0x00a5d018]
extern const char g_str_ct_00a5d018[];
// src: EXE [0x00a5d028]
extern const char g_str_eh_00a5d028[];
// src: EXE [0x00a5d038]
extern const char g_str_gc_00a5d038[];

void SetupCallbackThread_0057e2d0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5d018);
    lua_State* co = lua_newthread(L);
    PushFn_006f5b80(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5d028);
    EventHandle_0057e2d0* h = (EventHandle_0057e2d0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5d038);
    lua_pushcclosure(L, l_GC_00684250, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
