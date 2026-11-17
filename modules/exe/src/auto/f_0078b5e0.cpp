// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0078b5e0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0078b5e0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0070d930]
void PushFn_0070d930(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x0060c050]
int l_GC_0060c050(lua_State* L);
// src: EXE [0x00a5d674]
extern const char g_str_ct_00a5d674[];
// src: EXE [0x00a5d684]
extern const char g_str_eh_00a5d684[];
// src: EXE [0x00a5d694]
extern const char g_str_gc_00a5d694[];

void SetupCallbackThread_0078b5e0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5d674);
    lua_State* co = lua_newthread(L);
    PushFn_0070d930(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5d684);
    EventHandle_0078b5e0* h = (EventHandle_0078b5e0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5d694);
    lua_pushcclosure(L, l_GC_0060c050, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
