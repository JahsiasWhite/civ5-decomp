// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00752e10]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00752e10 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x006d0c90]
void PushFn_006d0c90(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00690280]
int l_GC_00690280(lua_State* L);
// src: EXE [0x00a5d424]
extern const char g_str_ct_00a5d424[];
// src: EXE [0x00a5d434]
extern const char g_str_eh_00a5d434[];
// src: EXE [0x00a5d444]
extern const char g_str_gc_00a5d444[];

void SetupCallbackThread_00752e10(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5d424);
    lua_State* co = lua_newthread(L);
    PushFn_006d0c90(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5d434);
    EventHandle_00752e10* h = (EventHandle_00752e10*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5d444);
    lua_pushcclosure(L, l_GC_00690280, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
