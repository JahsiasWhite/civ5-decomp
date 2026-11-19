// src: GUESS (confidence: high) [0x004364e0]
#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct Entry_004364e0 {
    int m_i00;
    int m_i04;
    char m_szName[256];
    int m_i108;
};

// src: GUESS (confidence: high) [0x004364e0]
void Lua_PushEntry_004364e0(lua_State* L, const Entry_004364e0* pEntry) {
    lua_pushinteger(L, pEntry->m_i00);
    lua_pushinteger(L, pEntry->m_i04);
    lua_pushstring(L, pEntry->m_szName);
    lua_pushinteger(L, pEntry->m_i108);
}
