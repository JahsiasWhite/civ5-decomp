#include "LuaApi.h"

// src: GUESS (confidence: low) [0x00b4f544]
extern int g_valA_0076fb50;
// src: GUESS (confidence: low) [0x00b4f548]
extern int g_valB_0076fb50;

// src: GUESS (confidence: high) [0x0076fb50]
int l_SetPair_0076fb50(lua_State* L)
{
    int b = lua_tointeger(L, 2);
    int a = lua_tointeger(L, 1);
    g_valB_0076fb50 = b;
    g_valA_0076fb50 = a;
    return 0;
}
