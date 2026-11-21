#include "LuaApi.h"

// src: LIB [0x00889546]
extern "C" int lua_toboolean(lua_State* L, int idx);

// src: GUESS (confidence: low)
struct UnkFlags_006dbaf0
{
    unsigned char m_b0 : 1;
    unsigned char m_b1 : 1;
};

// src: GUESS (confidence: medium) [0x006dbaf0]
void ReadLuaFlags2_006dbaf0(lua_State* L, UnkFlags_006dbaf0* out)
{
    out->m_b0 = (lua_toboolean(L, 1) != 0);
    out->m_b1 = (lua_toboolean(L, 2) != 0);
}
