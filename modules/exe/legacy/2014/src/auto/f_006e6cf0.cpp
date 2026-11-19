// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006e6cf0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_006e6cf0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x005be790]
void PushFn_005be790(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x007964a0]
int l_GC_007964a0(lua_State* L);
// src: EXE [0x00a58f58]
extern const char g_str_ct_00a58f58[];
// src: EXE [0x00a58f68]
extern const char g_str_eh_00a58f68[];
// src: EXE [0x00a58f78]
extern const char g_str_gc_00a58f78[];

void SetupCallbackThread_006e6cf0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a58f58);
    lua_State* co = lua_newthread(L);
    PushFn_005be790(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a58f68);
    EventHandle_006e6cf0* h = (EventHandle_006e6cf0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a58f78);
    lua_pushcclosure(L, l_GC_007964a0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
