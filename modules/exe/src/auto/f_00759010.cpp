// c5d-model: Gemini 3.8 Flash

#include "LuaApi.h"

// src: LIB [0x00923970]
extern "C" void lua_pushvalue(lua_State* L, int idx);

// src: EXE [0x00568400]
int l_Add(lua_State* L);
// src: EXE [0x0076c520]
int l_Count(lua_State* L);
// src: EXE [0x0067a9d0]
int l_Remove(lua_State* L);
// src: EXE [0x005c2ec0]
int l_RemoveAll(lua_State* L);
// src: EXE [0x00433620]
int l_Call(lua_State* L);
// src: EXE [0x00486fd0]
int l_Accumulate(lua_State* L);
// src: EXE [0x00530270]
int l_AccumulateINT(lua_State* L);
// src: EXE [0x005dd150]
int l_TestAny(lua_State* L);
// src: EXE [0x005a75e0]
int l_TestAll(lua_State* L);

// src: GUESS (confidence: high) [0x006cb4e0]
void RegisterLuaEvents_006cb4e0(lua_State* L, int tableIdx, int callUpvalue, int modifyUpvalue)
{
    lua_pushstring(L, "Add");
    lua_pushvalue(L, modifyUpvalue);
    lua_pushcclosure(L, l_Add, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "Count");
    lua_pushvalue(L, modifyUpvalue);
    lua_pushcclosure(L, l_Count, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "Remove");
    lua_pushvalue(L, modifyUpvalue);
    lua_pushcclosure(L, l_Remove, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "RemoveAll");
    lua_pushvalue(L, modifyUpvalue);
    lua_pushcclosure(L, l_RemoveAll, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "Call");
    lua_pushvalue(L, callUpvalue);
    lua_pushcclosure(L, l_Call, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "Accumulate");
    lua_pushvalue(L, callUpvalue);
    lua_pushcclosure(L, l_Accumulate, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "AccumulateINT");
    lua_pushvalue(L, callUpvalue);
    lua_pushcclosure(L, l_AccumulateINT, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "TestAny");
    lua_pushvalue(L, callUpvalue);
    lua_pushcclosure(L, l_TestAny, 1);
    lua_rawset(L, tableIdx);

    lua_pushstring(L, "TestAll");
    lua_pushvalue(L, callUpvalue);
    lua_pushcclosure(L, l_TestAll, 1);
    lua_rawset(L, tableIdx);
}
