// src: EXE [0x1000b3b0]
#include "LuaApi.h"

// src: GUESS (confidence: low)
struct MemoryStats_1000b3b0 {
    int maxUserAllocatedBytes;
    int currentUserAllocatedBytes;
    int currentAllocatedBytes;
    int currentReservedBytes;
    int currentOverheadBytes;
    int currentUncommittedBytes;
    int numRegions;
};

// src: GUESS [0x100066e0] (confidence: low)
extern void* GetSingleton_100066e0();

namespace Database {
namespace Scripting {

// src: EXE
struct Lua {
    // src: EXE [0x1000b3b0]
    static int __cdecl lGetMemoryUsage(lua_State* L);
};

int __cdecl Lua::lGetMemoryUsage(lua_State* L) {
    MemoryStats_1000b3b0* pStats = (MemoryStats_1000b3b0*)GetSingleton_100066e0();
    lua_createtable(L, 0, 7);
    int tbl = lua_gettop(L);
    lua_pushstring(L, "NumRegions");
    lua_pushinteger(L, pStats->numRegions);
    lua_rawset(L, tbl);
    lua_pushstring(L, "MaxUserAllocatedBytes");
    lua_pushinteger(L, pStats->maxUserAllocatedBytes);
    lua_rawset(L, tbl);
    lua_pushstring(L, "CurrentUserAllocatedBytes");
    lua_pushinteger(L, pStats->currentUserAllocatedBytes);
    lua_rawset(L, tbl);
    lua_pushstring(L, "CurrentAllocatedBytes");
    lua_pushinteger(L, pStats->currentAllocatedBytes);
    lua_rawset(L, tbl);
    lua_pushstring(L, "CurrentReservedBytes");
    lua_pushinteger(L, pStats->currentReservedBytes);
    lua_rawset(L, tbl);
    lua_pushstring(L, "CurrentOverheadBytes");
    lua_pushinteger(L, pStats->currentOverheadBytes);
    lua_rawset(L, tbl);
    lua_pushstring(L, "CurrentUncommitedBytes");
    lua_pushinteger(L, pStats->currentUncommittedBytes);
    lua_rawset(L, tbl);
    return 1;
}

}  // namespace Scripting
}  // namespace Database
