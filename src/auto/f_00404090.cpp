// Adds the "LuaEvent" function to the table below the top of the stack: a C
// closure whose upvalue is a table with weak values (metatable __mode = "v").

#include "LuaApi.h"

int LuaEventDispatch(lua_State* L);

int RegisterLuaEventFunction(lua_State* L)
{
    lua_pushstring(L, "LuaEvent");
    lua_createtable(L, 0, 0);
    lua_createtable(L, 1, 0);
    lua_pushstring(L, "__mode");
    lua_pushstring(L, "v");
    lua_rawset(L, -3);
    lua_setmetatable(L, -2);
    lua_pushcclosure(L, LuaEventDispatch, 1);
    lua_rawset(L, -3);
    return 0;
}
