// src: GUESS (confidence: high) [0x006b8d60]
#include "LuaApi.h"
#include "Database/DatabaseAPI.h"

namespace Database {
namespace Scripting {
// src: EXE
class Lua {
public:
    // src: EXE [0x009d6058]
    static CVGAMEDATABASE_API int __cdecl lGetMemoryUsage(lua_State* L);
    // src: EXE [0x009d605c]
    static CVGAMEDATABASE_API int __cdecl lCollectMemoryUsage(lua_State* L);
};  // class Lua
}  // namespace Scripting
}  // namespace Database

// src: GUESS (confidence: low) [0x00663810]
int __cdecl Lua_DbStatementCount_00663810(lua_State* L);
// src: GUESS (confidence: low) [0x006ddee0]
int __cdecl Lua_DbStatementSQL_006ddee0(lua_State* L);
// src: GUESS (confidence: low) [0x00640fb0]
int __cdecl Lua_DbQuery_00640fb0(lua_State* L);
// src: GUESS (confidence: low) [0x00672db0]
int __cdecl Lua_DbCreateQuery_00672db0(lua_State* L);

// src: EXE [0x00a5711c]
extern const char g_str_GetMemoryUsage_00a5711c[];
// src: EXE [0x00a5712c]
extern const char g_str_CollectMemoryUsage_00a5712c[];
// src: EXE [0x00a57140]
extern const char g_str_StatementCount_00a57140[];
// src: EXE [0x00a57150]
extern const char g_str_StatementSQL_00a57150[];
// src: EXE [0x00a57160]
extern const char g_str_Query_00a57160[];
// src: EXE [0x00a57168]
extern const char g_str_CreateQuery_00a57168[];

// src: GUESS (confidence: high) [0x006b8d60]
int Lua_RegisterDatabase_006b8d60(lua_State* L) {
    lua_createtable(L, 0, 0);
    int iTable = lua_gettop(L);

    lua_pushstring(L, g_str_GetMemoryUsage_00a5711c);
    lua_pushcclosure(L, Database::Scripting::Lua::lGetMemoryUsage, 0);
    lua_rawset(L, iTable);

    lua_pushstring(L, g_str_CollectMemoryUsage_00a5712c);
    lua_pushcclosure(L, Database::Scripting::Lua::lCollectMemoryUsage, 0);
    lua_rawset(L, iTable);

    lua_pushstring(L, g_str_StatementCount_00a57140);
    lua_pushcclosure(L, Lua_DbStatementCount_00663810, 0);
    lua_rawset(L, iTable);

    lua_pushstring(L, g_str_StatementSQL_00a57150);
    lua_pushcclosure(L, Lua_DbStatementSQL_006ddee0, 0);
    lua_rawset(L, iTable);

    lua_pushstring(L, g_str_Query_00a57160);
    lua_pushcclosure(L, Lua_DbQuery_00640fb0, 0);
    lua_rawset(L, iTable);

    lua_pushstring(L, g_str_CreateQuery_00a57168);
    lua_pushcclosure(L, Lua_DbCreateQuery_00672db0, 0);
    lua_rawset(L, iTable);

    return 1;
}
