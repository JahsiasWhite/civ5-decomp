#include "LuaApi.h"

// src: GUESS (confidence: low)
struct Record_0043f310 {
    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    char m_name[0x104];
    // src: GUESS (confidence: low)
    int m_vals[2];
    // src: GUESS (confidence: low)
    char m_labels[2][0x101];

    int GetVal(unsigned int i) const { return i <= 1 ? m_vals[i] : 0; }
    const char* GetLabel(unsigned int i) const { return 1u >= i ? m_labels[i] : 0; }
};

// src: GUESS 0x0043f310 (confidence: high)
void PushRecord_0043f310(lua_State* L, const Record_0043f310* rec) {
    lua_pushinteger(L, rec->m_id);
    lua_pushstring(L, rec->m_name);
    for (int i = 0; i < 2; ++i) {
        lua_pushinteger(L, rec->GetVal(i));
    }
    for (int i = 0; i < 2; ++i) {
        lua_pushstring(L, rec->GetLabel(i));
    }
}
