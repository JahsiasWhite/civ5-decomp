// src: GUESS (confidence: low) [0x006da620]
struct lua_State;

// src: LIB [0x008895ac]
extern "C" void __cdecl lua_rawgeti(lua_State* L, int idx, int n);
// src: LIB [0x00889552]
extern "C" double __cdecl lua_tonumber(lua_State* L, int idx);
// src: LIB [0x00889576]
extern "C" void __cdecl lua_settop(lua_State* L, int idx);

void __cdecl ReadLuaMat4x4(lua_State* L, int idx, float* out) {
    for (int i = 0; i < 4; ++i) {
        lua_rawgeti(L, idx, i + 1);
        for (int j = 0; j < 4; ++j) {
            lua_rawgeti(L, -1, j + 1);
            out[i * 4 + j] = (float)lua_tonumber(L, -1);
            lua_settop(L, -2);
        }
        lua_settop(L, -2);
    }
}
