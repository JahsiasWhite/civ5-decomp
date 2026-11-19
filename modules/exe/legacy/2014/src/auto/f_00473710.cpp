// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00473710]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00473710 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x005bd600]
void PushFn_005bd600(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00574d80]
int l_GC_00574d80(lua_State* L);
// src: EXE [0x00a5f890]
extern const char g_str_ct_00a5f890[];
// src: EXE [0x00a5f8a0]
extern const char g_str_eh_00a5f8a0[];
// src: EXE [0x00a5f8b0]
extern const char g_str_gc_00a5f8b0[];

void SetupCallbackThread_00473710(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5f890);
    lua_State* co = lua_newthread(L);
    PushFn_005bd600(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5f8a0);
    EventHandle_00473710* h = (EventHandle_00473710*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5f8b0);
    lua_pushcclosure(L, l_GC_00574d80, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
