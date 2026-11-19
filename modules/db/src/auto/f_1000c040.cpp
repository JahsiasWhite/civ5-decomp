// c5d-cflags: -/EHsc +/GS-
#include "LuaApi.h"

namespace Database {

class Connection;
class Results;

namespace Scripting {

// src: EXE
struct Lua {
    // src: EXE [0x1000b4c0]
    static Results* __cdecl PushDatabaseQuery(lua_State* L, Connection* pkDB, const char* szQuery);
    // src: EXE [0x1000c040]
    static void __cdecl PushDatabase(lua_State* L, Connection& kDB);
};

// src: GUESS [0x1000bfa0] (confidence: low)
int __cdecl LuaDBIndex_1000bfa0(lua_State* L);

void __cdecl Lua::PushDatabase(lua_State* L, Connection& kDB) {
    lua_createtable(L, 0, 0);
    int tblIdx = lua_gettop(L);
    lua_createtable(L, 0, 0);
    int mtIdx = lua_gettop(L);

    lua_pushlightuserdata(L, &kDB);
    lua_setfield(L, mtIdx, "__db");

    lua_pushlightuserdata(L, &kDB);
    PushDatabaseQuery(
        L, &kDB,
        "SELECT rowid FROM sqlite_master WHERE (name NOT LIKE 'sqlite%') and (type = 'table') and (tbl_name = ?) LIMIT 1;");
    lua_pushcclosure(L, LuaDBIndex_1000bfa0, 2);
    lua_setfield(L, mtIdx, "__index");
    lua_setmetatable(L, tblIdx);
}

}  // namespace Scripting
}  // namespace Database
