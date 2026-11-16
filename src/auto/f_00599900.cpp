// c5d-model: Gemini 4 Hydrogen
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State*, int);

// src: GUESS (confidence: high) [0x00599900]
void __cdecl GetLuaInt_00599900(lua_State* L, int* out) {
    *out = lua_tointeger(L, 1);
}
