// c5d-cflags: -/arch:SSE2
#include "LuaApi.h"

// src: GUESS (confidence: low)
struct UnkEntry32_00543260
{
    int m_v[8];
};

// src: GUESS (confidence: low) [0x02e41ecc]
extern unsigned int g_count_02e41ecc;
// src: GUESS (confidence: low) [0x02e41ed0]
extern UnkEntry32_00543260 g_arr_02e41ed0[];

// src: GUESS (confidence: high) [0x00543260]
int PushEntry_00543260(lua_State* L)
{
    unsigned int idx = (unsigned int)lua_tointeger(L, 2);
    if (idx <= g_count_02e41ecc)
    {
        UnkEntry32_00543260 e = g_arr_02e41ed0[idx];
        lua_pushinteger(L, e.m_v[0]);
        lua_pushinteger(L, e.m_v[1]);
        lua_pushinteger(L, e.m_v[2]);
        lua_pushinteger(L, e.m_v[3]);
        lua_pushinteger(L, e.m_v[4]);
        lua_pushinteger(L, e.m_v[5]);
        return 6;
    }
    return 0;
}
