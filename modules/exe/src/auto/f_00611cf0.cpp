// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00611cf0]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_00611cf0 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0043a6f0]
void PushFn_0043a6f0(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x0064c6e0]
int l_GC_0064c6e0(lua_State* L);
// src: EXE [0x00a5cc0c]
extern const char g_str_ct_00a5cc0c[];
// src: EXE [0x00a5cc1c]
extern const char g_str_eh_00a5cc1c[];
// src: EXE [0x00a5cc2c]
extern const char g_str_gc_00a5cc2c[];

void SetupCallbackThread_00611cf0(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5cc0c);
    lua_State* co = lua_newthread(L);
    PushFn_0043a6f0(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5cc1c);
    EventHandle_00611cf0* h = (EventHandle_00611cf0*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5cc2c);
    lua_pushcclosure(L, l_GC_0064c6e0, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
