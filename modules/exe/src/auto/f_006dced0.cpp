// src: GUESS (confidence: high) [0x00438ce0]
#include "LuaApi.h"
#include <cstring>

// src: GUESS (confidence: medium)
struct Entry_00438ce0 {
    int m_id;
    char m_szName[64];
};

// src: GUESS (confidence: high) [0x00438ce0]
void Lua_ReadEntry_00438ce0(lua_State* L, Entry_00438ce0* pOut) {
    pOut->m_id = lua_tointeger(L, 1);
    const char* szStr = lua_tolstring(L, 2, 0);
    strncpy_s(pOut->m_szName, 0x40, szStr, 0x3f);
}
