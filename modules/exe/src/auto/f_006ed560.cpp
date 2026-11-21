#include "LuaApi.h"

// src: LIB [0x00889534]
extern "C" void lua_createtable(lua_State* L, int narr, int nrec);
// src: LIB [0x0088951c]
extern "C" void lua_pushstring(lua_State* L, const char* s);
// src: LIB [0x008895b8]
extern "C" void lua_pushnil(lua_State* L);
// src: LIB [0x0088955e]
extern "C" void lua_rawset(lua_State* L, int idx);
// src: LIB [0x00889582]
extern "C" void lua_getfield(lua_State* L, int idx, const char* k);
// src: LIB [0x0088956a]
extern "C" void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
// src: LIB [0x008895dc]
extern "C" int lua_setmetatable(lua_State* L, int objindex);

// src: EXE [0x006e8eb0]
int ForwardCall_0073b5c0(lua_State* L);

// src: GUESS (confidence: high) [0x006ed560]
void InitCallMetatable_006ed560(lua_State* L)
{
    lua_createtable(L, 0, 3);
    lua_pushstring(L, "__newindex\0\0");
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pushstring(L, "__metatable\0\0");
    lua_createtable(L, 0, 0);
    lua_rawset(L, -3);
    lua_pushstring(L, "__call\0");
    lua_getfield(L, -3, "Call\0");
    lua_pushcclosure(L, ForwardCall_0073b5c0, 1);
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
}
