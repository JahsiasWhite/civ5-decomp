// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006a02a0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_006a02a0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0066a010]
void PushFn_0066a010(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00654b70]
int l_GC_00654b70(lua_State* L);
// src: EXE [0x00a5a300]
extern const char g_str_ct_00a5a300[];
// src: EXE [0x00a5a310]
extern const char g_str_eh_00a5a310[];
// src: EXE [0x00a5a320]
extern const char g_str_gc_00a5a320[];

void SetupCallbackThread_006a02a0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5a300);
    lua_State* co = lua_newthread(L);
    PushFn_0066a010(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5a310);
    EventHandle_006a02a0* h = (EventHandle_006a02a0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5a320);
    lua_pushcclosure(L, l_GC_00654b70, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
