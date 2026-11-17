// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00765ec0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00765ec0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x004d3ca0]
void PushFn_004d3ca0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x00709300]
int l_GC_00709300(lua_State* L);
// src: EXE [0x00a59898]
extern const char g_str_ct_00a59898[];
// src: EXE [0x00a598a8]
extern const char g_str_eh_00a598a8[];
// src: EXE [0x00a598b8]
extern const char g_str_gc_00a598b8[];

void SetupCallbackThread_00765ec0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a59898);
    lua_State* co = lua_newthread(L);
    PushFn_004d3ca0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a598a8);
    EventHandle_00765ec0* h = (EventHandle_00765ec0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a598b8);
    lua_pushcclosure(L, l_GC_00709300, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
