// Pushes four ints onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_005bf900
{
    int m_b;
    int m_a;
    char m_pad8[0x14 - 8];
    int m_c;
    int m_d;
};

// src: GUESS (confidence: low) [0x005bf900]
void PushRecord_005bf900(lua_State* L, const Record_005bf900* r)
{
    lua_pushinteger(L, r->m_a);
    lua_pushinteger(L, r->m_b);
    lua_pushinteger(L, r->m_c);
    lua_pushinteger(L, r->m_d);
}
