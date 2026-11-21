#include "LuaApi.h"

// src: LIB [0x00889564]
extern "C" const char* lua_tolstring(lua_State* L, int idx, size_t* len);
// src: LIB [0x00889546]
extern "C" int lua_toboolean(lua_State* L, int idx);

// src: GUESS (confidence: low)
struct UnkLuaArgs_006dbe30
{
    int a;
    const char* b;
    bool c;
};

// src: GUESS (confidence: medium) [0x006dbe30]
void ReadLuaArgs3_006dbe30(lua_State* L, UnkLuaArgs_006dbe30* out)
{
    out->a = lua_tointeger(L, 1);
    out->b = lua_tolstring(L, 2, 0);
    out->c = lua_toboolean(L, 3) != 0;
}
