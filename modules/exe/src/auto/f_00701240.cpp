// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00701240]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00701240 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x00673f80]
void PushFn_00673f80(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00435610]
int l_GC_00435610(lua_State* L);
// src: EXE [0x00a5e048]
extern const char g_str_ct_00a5e048[];
// src: EXE [0x00a5e058]
extern const char g_str_eh_00a5e058[];
// src: EXE [0x00a5e068]
extern const char g_str_gc_00a5e068[];

void SetupCallbackThread_00701240(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5e048);
    lua_State* co = lua_newthread(L);
    PushFn_00673f80(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5e058);
    EventHandle_00701240* h = (EventHandle_00701240*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5e068);
    lua_pushcclosure(L, l_GC_00435610, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
