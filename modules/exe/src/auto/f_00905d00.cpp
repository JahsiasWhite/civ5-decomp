// src: GUESS (confidence: medium) [0x00905d00]
#include "LuaApi.h"

// src: GUESS (confidence: low)
struct RegEntry_00905d00 {
    const char* m_szName;
    int m_i04;
    lua_CFunction m_pfn;
    void* m_pData;
};

// src: GUESS (confidence: low) [0x00904820]
void Lua_Helper_00904820(lua_State* L, void* pData);

// src: GUESS (confidence: low) [0x00cb9438]
extern unsigned int g_initFlags_00cb9438;
// src: GUESS (confidence: low) [0x00cc2320]
extern RegEntry_00905d00 g_regEntries_00cc2320[];
// src: GUESS (confidence: low) [0x00cc6320]
extern unsigned int g_numRegEntries_00cc6320;
// src: GUESS (confidence: low) [0x00cc6324]
extern void (__cdecl* g_callbacks_00cc6324[])(lua_State*);
// src: GUESS (confidence: low) [0x00cc7324]
extern unsigned int g_numCallbacks_00cc7324;

// src: GUESS (confidence: medium) [0x00905d00]
void Lua_RegisterAll_00905d00(lua_State* L) {
    if ((g_initFlags_00cb9438 & 1) == 0) {
        g_initFlags_00cb9438 |= 1;
        g_numRegEntries_00cc6320 = 0;
        g_numCallbacks_00cc7324 = 0;
    }
    for (unsigned int i = 0; i < g_numRegEntries_00cc6320; ++i) {
        lua_pushcclosure(L, g_regEntries_00cc2320[i].m_pfn, 0);
        Lua_Helper_00904820(L, g_regEntries_00cc2320[i].m_pData);
        lua_setfield(L, LUA_GLOBALSINDEX, g_regEntries_00cc2320[i].m_szName);
    }
    unsigned int i = 0;
    if (i < g_numCallbacks_00cc7324) {
        typedef void (__cdecl* CallbackFn)(lua_State*);
        CallbackFn* ppFn = g_callbacks_00cc6324;
        do {
            (*ppFn)(L);
            ++i;
            ++ppFn;
        } while (i < g_numCallbacks_00cc7324);
    }
}
