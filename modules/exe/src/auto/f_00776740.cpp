struct lua_State;

extern "C" {
// src: LIB (confidence: high) [0x00889618]
void __cdecl luaL_checktype(lua_State* L, int narg, int t);
// src: LIB (confidence: high) [0x008895b8]
void __cdecl lua_pushnil(lua_State* L);
// src: LIB (confidence: high) [0x0088963c]
int __cdecl lua_next(lua_State* L, int idx);
// src: LIB (confidence: high) [0x00889576]
void __cdecl lua_settop(lua_State* L, int idx);
// src: LIB (confidence: high) [0x00889540]
void __cdecl lua_pushinteger(lua_State* L, int n);
}

// src: GUESS (confidence: high) [0x00776740]
int __cdecl luaTableCount_00776740(lua_State* L) {
    luaL_checktype(L, 1, 5);
    int count = 0;
    lua_pushnil(L);
    while (lua_next(L, 1) != 0) {
        ++count;
        lua_settop(L, -2);
    }
    lua_pushinteger(L, count);
    return 1;
}
