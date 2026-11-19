#include "LuaApi.h"

// src: GUESS (confidence: low)
struct UnkPair_005c8ee0
{
    int m_a;
    int m_b;
};

// src: GUESS (confidence: high) [0x005c8ee0]
void PushData_005c8ee0(lua_State* L, const UnkPair_005c8ee0* arr)
{
    for (int i = 0; i < 2; ++i)
    {
        lua_pushinteger(L, arr[i].m_a);
        lua_pushinteger(L, arr[i].m_b);
        lua_pushinteger(L, arr[i + 4].m_a);
        lua_pushinteger(L, arr[i + 4].m_b);
    }
}
