// __tostring for typed userdata: "Metatable for type: " followed by the
// metatable's CTypeName, or "Unknown" when it has none.

#include "LuaApi.h"

int MetatableToString(lua_State* L)
{
    lua_pushstring(L, "Metatable for type: ");
    lua_getfield(L, -2, "CTypeName");
    if (!lua_isstring(L, -1))
    {
        lua_settop(L, -2);
        lua_pushstring(L, "Unknown");
    }
    lua_concat(L, 2);
    return 1;
}
