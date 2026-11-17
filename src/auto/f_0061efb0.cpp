// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0061efb0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0061efb0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x004a3df0]
void PushFn_004a3df0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00734d50]
int l_GC_00734d50(lua_State* L);
// src: EXE [0x00a61984]
extern const char g_str_ct_00a61984[];
// src: EXE [0x00a61994]
extern const char g_str_eh_00a61994[];
// src: EXE [0x00a619a4]
extern const char g_str_gc_00a619a4[];

void SetupCallbackThread_0061efb0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a61984);
    lua_State* co = lua_newthread(L);
    PushFn_004a3df0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a61994);
    EventHandle_0061efb0* h = (EventHandle_0061efb0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a619a4);
    lua_pushcclosure(L, l_GC_00734d50, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
