// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x0043b050]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct EventHandle_0043b050 {
    lua_State* thread;
    int ref;
    bool active;
};

// src: GUESS (confidence: high) [0x0040ce80]
void PushFn_0040ce80(lua_State* L, int idx);
// src: GUESS (confidence: high) [0x006a6710]
int l_GC_006a6710(lua_State* L);
// src: EXE [0x00a5b208]
extern const char g_str_ct_00a5b208[];
// src: EXE [0x00a5b218]
extern const char g_str_eh_00a5b218[];
// src: EXE [0x00a5b228]
extern const char g_str_gc_00a5b228[];

void SetupCallbackThread_0043b050(lua_State* L, int idx) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_ct_00a5b208);
    lua_State* co = lua_newthread(L);
    PushFn_0040ce80(L, idx);
    lua_setfenv(L, -2);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_eh_00a5b218);
    EventHandle_0043b050* h = (EventHandle_0043b050*)lua_newuserdata(L, 0xc);
    if (h) {
        h->thread = co;
        h->active = false;
    }
    lua_createtable(L, 0, 1);
    lua_pushstring(L, g_str_gc_00a5b228);
    lua_pushcclosure(L, l_GC_006a6710, 0);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_rawset(L, -3);
}
