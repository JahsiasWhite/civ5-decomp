// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006727c0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_006727c0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0055f610]
void PushFn_0055f610(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006b28b0]
int l_GC_006b28b0(lua_State* L);
// src: EXE [0x00a58c74]
extern const char g_str_ct_00a58c74[];
// src: EXE [0x00a58c84]
extern const char g_str_eh_00a58c84[];
// src: EXE [0x00a58c94]
extern const char g_str_gc_00a58c94[];

void SetupCallbackThread_006727c0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a58c74);
    lua_State* co = lua_newthread(L);
    PushFn_0055f610(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a58c84);
    EventHandle_006727c0* h = (EventHandle_006727c0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a58c94);
    lua_pushcclosure(L, l_GC_006b28b0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
