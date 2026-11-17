// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x006f6980]

#include "LuaApi.h"

void GetLuaBool_006f6980(lua_State* L, bool* out) {
    *out = (char)lua_toboolean(L, 1) != 0;
}
