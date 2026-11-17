// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006917d0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_006917d0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x00413710]
void PushFn_00413710(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006173b0]
int l_GC_006173b0(lua_State* L);
// src: EXE [0x00a5f3f0]
extern const char g_str_ct_00a5f3f0[];
// src: EXE [0x00a5f400]
extern const char g_str_eh_00a5f400[];
// src: EXE [0x00a5f410]
extern const char g_str_gc_00a5f410[];

void SetupCallbackThread_006917d0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5f3f0);
    lua_State* co = lua_newthread(L);
    PushFn_00413710(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5f400);
    EventHandle_006917d0* h = (EventHandle_006917d0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5f410);
    lua_pushcclosure(L, l_GC_006173b0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
