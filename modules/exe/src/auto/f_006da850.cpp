// c5d-cflags: -/arch:SSE2 +/Os
#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct Vec3_00672df0
{
    // src: GUESS (confidence: high)
    float x;
    // src: GUESS (confidence: high)
    float y;
    // src: GUESS (confidence: high)
    float z;
};

// src: GUESS (confidence: high) [0x00672df0]
void PushVec3_00672df0(lua_State* L, const Vec3_00672df0* v)
{
    lua_createtable(L, 0, 3);
    lua_pushstring(L, "x");
    lua_pushnumber(L, v->x);
    lua_rawset(L, -3);
    lua_pushstring(L, "y");
    lua_pushnumber(L, v->y);
    lua_rawset(L, -3);
    lua_pushstring(L, "z");
    lua_pushnumber(L, v->z);
    lua_rawset(L, -3);
}
