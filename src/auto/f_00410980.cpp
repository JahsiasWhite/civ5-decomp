// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00410980]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00410980 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x005c3e40]
void PushFn_005c3e40(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x0076cfd0]
int l_GC_0076cfd0(lua_State* L);
// src: EXE [0x00a59ca4]
extern const char g_str_ct_00a59ca4[];
// src: EXE [0x00a59cb4]
extern const char g_str_eh_00a59cb4[];
// src: EXE [0x00a59cc4]
extern const char g_str_gc_00a59cc4[];

void SetupCallbackThread_00410980(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a59ca4);
    lua_State* co = lua_newthread(L);
    PushFn_005c3e40(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a59cb4);
    EventHandle_00410980* h = (EventHandle_00410980*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a59cc4);
    lua_pushcclosure(L, l_GC_0076cfd0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
