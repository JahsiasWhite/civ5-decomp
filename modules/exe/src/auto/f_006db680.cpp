#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Unk_006db680
{
    int m_pad00;  // +0x00
    int m_f04;    // +0x04
    int m_f08;    // +0x08
};

// src: GUESS (confidence: high) [0x006db680]
void ReadPair_006db680(lua_State* L, Unk_006db680* p)
{
    p->m_f04 = lua_tointeger(L, 1);
    p->m_f08 = lua_tointeger(L, 2);
}
