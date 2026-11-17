// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00664ca0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00664ca0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x004060c0]
void PushFn_004060c0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x004997e0]
int l_GC_004997e0(lua_State* L);
// src: EXE [0x00a5a5e4]
extern const char g_str_ct_00a5a5e4[];
// src: EXE [0x00a5a5f4]
extern const char g_str_eh_00a5a5f4[];
// src: EXE [0x00a5a604]
extern const char g_str_gc_00a5a604[];

void SetupCallbackThread_00664ca0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5a5e4);
    lua_State* co = lua_newthread(L);
    PushFn_004060c0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5a5f4);
    EventHandle_00664ca0* h = (EventHandle_00664ca0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5a604);
    lua_pushcclosure(L, l_GC_004997e0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
