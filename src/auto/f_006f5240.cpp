// c5d-model: Gemini 4 Hydrogen
struct lua_State;
extern "C" void __cdecl lua_pushlstring(lua_State* L, const char* s, unsigned int len);

// src: GUESS (confidence: high) [0x006f5240]
void __cdecl PushFixedString_006f5240(lua_State* L, const char* s) {
    lua_pushlstring(L, s, 0x80);
}
