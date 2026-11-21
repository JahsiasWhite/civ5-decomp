#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "LuaApi.h"

// src: LIB [0x008895fa]
extern "C" const char* luaL_checklstring(lua_State* L, int numArg, size_t* l);

// src: GUESS (confidence: high) [0x006dae80]
void CheckLuaWideString_006dae80(lua_State* L, wchar_t* out)
{
    const char* s = luaL_checklstring(L, 1, 0);
    out[0] = 0;
    if (s)
        MultiByteToWideChar(CP_UTF8, 0, s, -1, out, 0x104);
}
