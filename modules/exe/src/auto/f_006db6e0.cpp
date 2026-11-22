#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006db6e0]
void NotificationActivatedFromLua(lua_State* L, int idx)
{
    luaL_error(L, "FromLua called on NotificationActivated- this shouldn't happen.");
}
