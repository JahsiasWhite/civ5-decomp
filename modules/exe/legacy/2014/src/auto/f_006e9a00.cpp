// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006e9a00]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_006e9a00 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0056a9c0]
void PushFn_0056a9c0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00531b70]
int l_GC_00531b70(lua_State* L);
// src: EXE [0x00a5b614]
extern const char g_str_ct_00a5b614[];
// src: EXE [0x00a5b624]
extern const char g_str_eh_00a5b624[];
// src: EXE [0x00a5b634]
extern const char g_str_gc_00a5b634[];

void SetupCallbackThread_006e9a00(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5b614);
    lua_State* co = lua_newthread(L);
    PushFn_0056a9c0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5b624);
    EventHandle_006e9a00* h = (EventHandle_006e9a00*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5b634);
    lua_pushcclosure(L, l_GC_00531b70, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
