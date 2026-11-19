// Pushes the first two flag bits of a record onto the Lua stack as booleans.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Flags_00595400
{
    // src: GUESS (confidence: low)
    unsigned char m_first : 1;
    // src: GUESS (confidence: low)
    unsigned char m_second : 1;
};

// src: GUESS (confidence: low) [0x00595400]
void PushFlags_00595400(lua_State* L, const Flags_00595400* flags)
{
    lua_pushboolean(L, flags->m_first);
    lua_pushboolean(L, flags->m_second);
}
