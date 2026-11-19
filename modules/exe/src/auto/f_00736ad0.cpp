// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00560fa0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00560fa0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0076a130]
void PushFn_0076a130(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006d1180]
int l_GC_006d1180(lua_State* L);
// src: EXE [0x00a5b580]
extern const char g_str_ct_00a5b580[];
// src: EXE [0x00a5b590]
extern const char g_str_eh_00a5b590[];
// src: EXE [0x00a5b5a0]
extern const char g_str_gc_00a5b5a0[];

void SetupCallbackThread_00560fa0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5b580);
    lua_State* co = lua_newthread(L);
    PushFn_0076a130(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5b590);
    EventHandle_00560fa0* h = (EventHandle_00560fa0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5b5a0);
    lua_pushcclosure(L, l_GC_006d1180, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
