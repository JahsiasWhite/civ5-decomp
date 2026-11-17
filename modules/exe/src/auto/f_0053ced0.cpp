// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0053ced0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0053ced0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x00490850]
void PushFn_00490850(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006753e0]
int l_GC_006753e0(lua_State* L);
// src: EXE [0x00a609e8]
extern const char g_str_ct_00a609e8[];
// src: EXE [0x00a609f8]
extern const char g_str_eh_00a609f8[];
// src: EXE [0x00a60a08]
extern const char g_str_gc_00a60a08[];

void SetupCallbackThread_0053ced0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a609e8);
    lua_State* co = lua_newthread(L);
    PushFn_00490850(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a609f8);
    EventHandle_0053ced0* h = (EventHandle_0053ced0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a60a08);
    lua_pushcclosure(L, l_GC_006753e0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
