// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x0075d240]

#include "LuaApi.h"

// src: GUESS (confidence: high)
struct Vec2_0075d240 {
    float x;
    float y;
};

// src: EXE [0x00a55c80]
extern const char g_str_x_00a55c80[];
// src: EXE [0x00a55c84]
extern const char g_str_y_00a55c84[];

void PushVec2_0075d240(lua_State* L, const Vec2_0075d240* v) {
    lua_createtable(L, 0, 2);
    lua_pushstring(L, g_str_x_00a55c80);
    lua_pushnumber(L, v->x);
    lua_rawset(L, -3);
    lua_pushstring(L, g_str_y_00a55c84);
    lua_pushnumber(L, v->y);
    lua_rawset(L, -3);
}
