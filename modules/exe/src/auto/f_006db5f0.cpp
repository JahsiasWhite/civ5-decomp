#include "LuaApi.h"

// src: GUESS (confidence: low) [0x006db5f0]
void NotificationAddedFromLua(lua_State* L, int idx)
{
    luaL_error(L, "FromLua called on NotificationAdded- this shouldn't happen.   Use UI.AddNotification()");
}
