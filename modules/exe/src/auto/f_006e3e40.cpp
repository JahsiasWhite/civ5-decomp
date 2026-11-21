#include "LuaApi.h"
#include "Database/Connection.h"

// src: EXE
struct EngineOwner_006e3e40
{
    char m_pad[0x944];
    Database::Connection m_db;
};

// src: EXE [0x00b49338]
extern EngineOwner_006e3e40* g_pEngineOwner_00cc8e74;

// src: LIB [0x00889606]
extern "C" int luaL_checkinteger(lua_State* L, int numArg);
// src: LIB [0x0088951c]
extern "C" void lua_pushstring(lua_State* L, const char* s);

// src: GUESS (confidence: high) [0x006e3e40]
int LuaGetStatementSQL_006e3e40(lua_State* L)
{
    int idx = luaL_checkinteger(L, 1);
    Database::Connection& db = g_pEngineOwner_00cc8e74->m_db;
    const char* sql = db.StatementSQL(idx);
    lua_pushstring(L, sql);
    return 1;
}
