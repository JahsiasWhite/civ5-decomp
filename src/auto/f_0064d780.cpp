// Pushes the second int of a pair onto the Lua stack.

#include "LuaApi.h"

// src: GUESS (confidence: low) [0x0064d780]
struct IntPair_0064d780
{
    int first;
    int second;
};

// src: GUESS (confidence: low) [0x0064d780]
void PushPairSecondToLua(lua_State* L, const IntPair_0064d780* pair)
{
    lua_pushinteger(L, pair->second);
}
