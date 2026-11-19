#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct IntPair_006a2c90 {
    int m_x;
    int m_y;
};

// src: GUESS (confidence: medium) [0x006a2c90]
void Lua_ReadIntPair_006a2c90(lua_State* L, IntPair_006a2c90* out) {
    out->m_x = lua_tointeger(L, 1);
    out->m_y = lua_tointeger(L, 2);
}
