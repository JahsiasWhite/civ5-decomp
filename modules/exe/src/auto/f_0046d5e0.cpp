// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2 -/fp:fast
struct lua_State;
extern "C" double __cdecl lua_tonumber(lua_State*, int);

// src: GUESS (confidence: high) [0x0046d5e0]
void __cdecl GetLuaFloat_0046d5e0(lua_State* L, float* out) {
    *out = (float)lua_tonumber(L, 1);
}
