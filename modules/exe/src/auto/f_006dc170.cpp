#include "LuaApi.h"

// src: GUESS (confidence: low)
struct IntFloat_006dc170
{
    int m_i;    // +0x00
    float m_f;  // +0x04
};

// src: GUESS (confidence: high) [0x006dc170]
void ReadIntFloat_006dc170(lua_State* L, IntFloat_006dc170* p)
{
    p->m_i = lua_tointeger(L, 1);
    p->m_f = (float)lua_tonumber(L, 2);
}
