// Pushes three flags onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Flags_00683b40
{
    bool m_a;
    bool m_b;
    bool m_c;
};

// src: GUESS (confidence: low) [0x00683b40]
void PushFlags_00683b40(lua_State* L, const Flags_00683b40* f)
{
    lua_pushboolean(L, f->m_a);
    lua_pushboolean(L, f->m_b);
    lua_pushboolean(L, f->m_c);
}
