#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Entry_007068c0 {
    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    const char* m_name;
    // src: GUESS (confidence: low)
    bool m_flag;
};

// src: GUESS 0x007068c0 (confidence: high)
void PushEntry_007068c0(lua_State* L, const Entry_007068c0* entry) {
    lua_pushinteger(L, entry->m_id);
    lua_pushstring(L, entry->m_name);
    lua_pushboolean(L, entry->m_flag);
}
