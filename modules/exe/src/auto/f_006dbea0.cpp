struct lua_State;

// src: EXE [0x0088954c]
extern "C" int __cdecl lua_tointeger(lua_State* L, int idx);
// src: EXE [0x00889546]
extern "C" int __cdecl lua_toboolean(lua_State* L, int idx);

// src: GUESS (confidence: low) [0x006dbea0]
struct Out6DBEA0 {
    int  m_00;
    bool m_04;
    bool m_05;
};

// src: GUESS (confidence: low) [0x006dbea0]
void __cdecl parseArgs6DBEA0(lua_State* L, Out6DBEA0* out) {
    out->m_00 = lua_tointeger(L, 1);
    out->m_04 = lua_toboolean(L, 2) != 0;
    out->m_05 = lua_toboolean(L, 3) != 0;
}
