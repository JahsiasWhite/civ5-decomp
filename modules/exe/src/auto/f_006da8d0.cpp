#include "LuaApi.h"

// src: GUESS (confidence: low)
struct UnkShortPair_006da8d0
{
    short a;
    short b;
};

// src: GUESS (confidence: medium) [0x006da8d0]
void ReadLuaShortPair_006da8d0(lua_State* L, UnkShortPair_006da8d0* out)
{
    out->a = (short)lua_tointeger(L, 1);
    out->b = (short)lua_tointeger(L, 2);
}
