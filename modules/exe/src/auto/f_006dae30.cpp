#include <string.h>
#include "LuaApi.h"

// src: LIB [0x00889564]
extern "C" const char* lua_tolstring(lua_State* L, int idx, size_t* len);

// src: GUESS (confidence: high) [0x006dae30]
void ReadLuaStr128_006dae30(lua_State* L, char* out)
{
    const char* s = lua_tolstring(L, 1, 0);
    out[0] = 0;
    if (s)
    {
        strncpy(out, lua_tolstring(L, 1, 0), 0x80);
        out[0x7f] = 0;
    }
}
