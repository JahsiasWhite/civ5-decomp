// src: EXE [0x1000be80]
#include "LuaApi.h"

namespace Database {

class Connection;

namespace Scripting {

// src: EXE
struct Lua {
    // src: EXE [0x1000be80]
    static void __cdecl PushDatabaseTable(lua_State* L, Connection& kDB, const char* szTableName);
};

// src: GUESS [0x1000bcb0] (confidence: low)
int __cdecl LuaTableIndex_1000bcb0(lua_State* L);
// src: GUESS [0x1000b390] (confidence: low)
int __cdecl LuaTableNewIndex_1000b390(lua_State* L);
// src: GUESS [0x1000bdd0] (confidence: low)
int __cdecl LuaTableLen_1000bdd0(lua_State* L);
// src: GUESS [0x1000b870] (confidence: low)
int __cdecl LuaTableCall_1000b870(lua_State* L);

void __cdecl Lua::PushDatabaseTable(lua_State* L, Connection& kDB, const char* szTableName) {
    lua_newuserdata(L, 4);
    int udIdx = lua_gettop(L);
    lua_createtable(L, 0, 0);
    int mtIdx = lua_gettop(L);

    lua_pushvalue(L, mtIdx);
    lua_pushcclosure(L, LuaTableIndex_1000bcb0, 1);
    lua_setfield(L, mtIdx, "__index");

    lua_pushcclosure(L, LuaTableNewIndex_1000b390, 0);
    lua_setfield(L, mtIdx, "__newindex");

    lua_pushvalue(L, mtIdx);
    lua_pushcclosure(L, LuaTableLen_1000bdd0, 1);
    lua_setfield(L, mtIdx, "__len");

    lua_pushvalue(L, mtIdx);
    lua_pushcclosure(L, LuaTableCall_1000b870, 1);
    lua_setfield(L, mtIdx, "__call");

    lua_pushstring(L, szTableName);
    lua_setfield(L, mtIdx, "__tablename");

    lua_pushlightuserdata(L, &kDB);
    lua_setfield(L, mtIdx, "__db");

    lua_createtable(L, 0, 0);
    lua_setfield(L, mtIdx, "__rowdata");

    if (lua_gettop(L) != mtIdx) {
        luaL_error(L, "Stack size does not match expected value.");
    }
    lua_setmetatable(L, udIdx);
}

}  // namespace Scripting
}  // namespace Database
