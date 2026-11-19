// src: GUESS (confidence: high) [0x004a8c90]
#include "LuaApi.h"

// src: GUESS (confidence: medium)
struct Entry_004a8c90 {
    int m_i00;
    int m_i04;
    char m_szName[1024];
    int m_i408;
    int m_i40c;
};

// src: GUESS (confidence: high) [0x004a8c90]
void Lua_PushEntry_004a8c90(lua_State* L, const Entry_004a8c90* pEntry) {
    lua_pushinteger(L, pEntry->m_i00);
    lua_pushinteger(L, pEntry->m_i04);
    lua_pushstring(L, pEntry->m_szName);
    lua_pushinteger(L, pEntry->m_i408);
    lua_pushinteger(L, pEntry->m_i40c);
}
