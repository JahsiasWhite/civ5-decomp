#pragma once

// The Lua 5.1 C API the exe imports from lua51_Win32.dll. The exe calls each one
// through a `jmp [IAT]` stub, so their symbols map to those stubs (e.g.
// `0x0092391c _lua_pushstring`). Add functions here as tasks need them.

struct lua_State;
typedef int (*lua_CFunction)(lua_State* L);

extern "C" {
void lua_settop(lua_State* L, int idx);
int lua_isstring(lua_State* L, int idx);
void lua_pushstring(lua_State* L, const char* s);
void lua_pushlstring(lua_State* L, const char* s, unsigned int len);
void lua_pushboolean(lua_State* L, int b);
void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
void lua_createtable(lua_State* L, int narr, int nrec);
void lua_getfield(lua_State* L, int idx, const char* k);
void lua_rawset(lua_State* L, int idx);
int lua_setmetatable(lua_State* L, int objindex);
void lua_pushnil(lua_State* L);
void lua_concat(lua_State* L, int n);
void lua_pushinteger(lua_State* L, int n);
int luaL_error(lua_State* L, const char* fmt, ...);
}
