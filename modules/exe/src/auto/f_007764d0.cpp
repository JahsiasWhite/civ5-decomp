#include "LuaApi.h"

// src: GUESS 0x02dd2080 (confidence: high)
extern unsigned long g_uTrackedAllocPeakBytes;
// src: GUESS 0x02dd2084 (confidence: high)
extern unsigned long g_uTrackedAllocCurBytes;
// src: GUESS 0x02dd2088 (confidence: high)
extern unsigned long g_uTrackedAllocCurrentAllocatedBytes_02dd2088;
// src: GUESS 0x02dd208c (confidence: high)
extern unsigned long g_uTrackedAllocCurrentReservedBytes_02dd208c;
// src: GUESS 0x02dd2090 (confidence: high)
extern unsigned long g_uTrackedAllocCurrentOverheadBytes_02dd2090;
// src: GUESS 0x02dd2094 (confidence: high)
extern unsigned long g_uTrackedAllocCurrentUncommittedBytes_02dd2094;
// src: GUESS 0x02dd2098 (confidence: high)
extern unsigned long g_uTrackedAllocNumRegions_02dd2098;

// src: EXE [0x005493f0]
int l_GetLuaMemoryUsage(lua_State* L) {
    lua_createtable(L, 0, 7);
    int tableIdx = lua_gettop(L);

    lua_pushstring(L, "NumRegions");
    lua_pushinteger(L, g_uTrackedAllocNumRegions_02dd2098);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "MaxUserAllocatedBytes");
    lua_pushinteger(L, g_uTrackedAllocPeakBytes);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "CurrentUserAllocatedBytes");
    lua_pushinteger(L, g_uTrackedAllocCurBytes);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "CurrentAllocatedBytes");
    lua_pushinteger(L, g_uTrackedAllocCurrentAllocatedBytes_02dd2088);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "CurrentReservedBytes");
    lua_pushinteger(L, g_uTrackedAllocCurrentReservedBytes_02dd208c);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "CurrentOverheadBytes");
    lua_pushinteger(L, g_uTrackedAllocCurrentOverheadBytes_02dd2090);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "CurrentUncommitedBytes");
    lua_pushinteger(L, g_uTrackedAllocCurrentUncommittedBytes_02dd2094);
    lua_rawset(L, tableIdx);

    return 1;
}
