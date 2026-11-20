#include "LuaApi.h"

// src: GUESS (confidence: low)
struct FloatInt_006db480
{
    float m_f;  // +0x00
    int m_i;    // +0x04
};

// src: GUESS (confidence: high) [0x006db480]
void ReadFloatInt_006db480(lua_State* L, FloatInt_006db480* p)
{
    p->m_i = lua_tointeger(L, 1);
    p->m_f = (float)lua_tonumber(L, 2);
}
