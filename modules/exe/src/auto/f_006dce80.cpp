#include <string.h>
#include "LuaApi.h"

// src: LIB [0x00889564]
extern "C" const char* lua_tolstring(lua_State* L, int idx, size_t* len);

// src: GUESS (confidence: low)
struct UnkStr512_006dce80
{
    int m_id;
    char m_buf[0x200];
};

// src: GUESS (confidence: high) [0x006dce80]
void ReadLuaIdStr512_006dce80(lua_State* L, UnkStr512_006dce80* out)
{
    out->m_id = lua_tointeger(L, 1);
    const char* s = lua_tolstring(L, 2, 0);
    if (s)
    {
        strncpy(out->m_buf, s, 0x200);
        out->m_buf[0x1ff] = 0;
    }
}
