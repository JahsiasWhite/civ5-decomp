// c5d-cflags: -/arch:SSE2   (x87 Lua binding, like the other lua_pushnumber callers)
// Pushes a numbered name onto the Lua stack: the number, then the string.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct NumberedName_00762ab0
{
    // src: GUESS (confidence: low)
    int m_number;
    // src: GUESS (confidence: low)
    char m_name[1];
};

// src: GUESS (confidence: low) [0x00762ab0]
void PushNumberedName(lua_State* L, const NumberedName_00762ab0* value)
{
    lua_pushnumber(L, value->m_number);
    lua_pushstring(L, value->m_name);
}
