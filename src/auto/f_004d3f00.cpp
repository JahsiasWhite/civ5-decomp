// c5d-model: claude-opus-5-5
// Pushes a C++ bool onto the Lua stack.

#include "LuaApi.h"

void PushBoolToLua(lua_State* L, const bool* value)
{
    lua_pushboolean(L, *value);
}
