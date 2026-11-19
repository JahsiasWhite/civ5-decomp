// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0063c1a0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0063c1a0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x006ea3b0]
void PushFn_006ea3b0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00490ec0]
int l_GC_00490ec0(lua_State* L);
// src: EXE [0x00a5bbdc]
extern const char g_str_ct_00a5bbdc[];
// src: EXE [0x00a5bbec]
extern const char g_str_eh_00a5bbec[];
// src: EXE [0x00a5bbfc]
extern const char g_str_gc_00a5bbfc[];

void SetupCallbackThread_0063c1a0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5bbdc);
    lua_State* co = lua_newthread(L);
    PushFn_006ea3b0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5bbec);
    EventHandle_0063c1a0* h = (EventHandle_0063c1a0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5bbfc);
    lua_pushcclosure(L, l_GC_00490ec0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
