// c5d-model: Gemini 4 Hydrogen
struct lua_State;
extern "C" int __cdecl lua_tointeger(lua_State*, int);

struct Target_005d5680 {
    int pad;
    int val;
};

// src: GUESS (confidence: high) [0x005d5680]
void __cdecl GetLuaInt2_005d5680(lua_State* L, Target_005d5680* out) {
    out->val = lua_tointeger(L, 1);
}
