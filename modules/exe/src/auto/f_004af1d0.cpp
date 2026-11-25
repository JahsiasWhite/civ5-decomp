// src: GUESS (confidence: low)
struct lua_State;
extern "C" {
    void __cdecl lua_createtable(lua_State* L, int narr, int nrec);
    int __cdecl lua_gettop(lua_State* L);
    void __cdecl lua_pushstring(lua_State* L, const char* s);
    void __cdecl lua_setfield(lua_State* L, int idx, const char* k);
    void __cdecl lua_rawseti(lua_State* L, int idx, int n);
}

void __stdcall f_004af1d0(lua_State* L, const char* modId, const char* name, int tblIdx, int* counter) {
    lua_createtable(L, 0, 0);
    int top = lua_gettop(L);
    lua_pushstring(L, modId);
    lua_setfield(L, top, "ModID");
    lua_pushstring(L, name);
    lua_setfield(L, top, "Name");
    int idx = (*counter)++;
    lua_rawseti(L, tblIdx, idx);
}
