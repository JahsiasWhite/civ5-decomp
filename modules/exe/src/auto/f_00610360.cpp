// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00610360]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00610360 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x00580b40]
void PushFn_00580b40(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00578290]
int l_GC_00578290(lua_State* L);
// src: EXE [0x00a5ca50]
extern const char g_str_ct_00a5ca50[];
// src: EXE [0x00a5ca60]
extern const char g_str_eh_00a5ca60[];
// src: EXE [0x00a5ca70]
extern const char g_str_gc_00a5ca70[];

void SetupCallbackThread_00610360(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5ca50);
    lua_State* co = lua_newthread(L);
    PushFn_00580b40(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5ca60);
    EventHandle_00610360* h = (EventHandle_00610360*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5ca70);
    lua_pushcclosure(L, l_GC_00578290, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
