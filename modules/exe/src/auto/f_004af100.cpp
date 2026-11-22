// c5d-cflags: -/Ob1 +/Ob0
#include <string>
#include "LuaApi.h"

// src: GUESS (confidence: low) [0x004af100]
class Class_004af100
{
public:
    unsigned char m_pad[0x64];
    std::string m_str;

    void PushStr(lua_State* L);
};

void Class_004af100::PushStr(lua_State* L)
{
    lua_pushstring(L, m_str.c_str());
}
