// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x007aceb0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_007aceb0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0059dc60]
void PushFn_0059dc60(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006483f0]
int l_GC_006483f0(lua_State* L);
// src: EXE [0x00a610d8]
extern const char g_str_ct_00a610d8[];
// src: EXE [0x00a610e8]
extern const char g_str_eh_00a610e8[];
// src: EXE [0x00a610f8]
extern const char g_str_gc_00a610f8[];

void SetupCallbackThread_007aceb0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a610d8);
    lua_State* co = lua_newthread(L);
    PushFn_0059dc60(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a610e8);
    EventHandle_007aceb0* h = (EventHandle_007aceb0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a610f8);
    lua_pushcclosure(L, l_GC_006483f0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
