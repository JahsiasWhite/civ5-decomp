// c5d-model: Gemini 3.8 Flash
// c5d-review: Lua error thunk setting error string and tail-jumping to luaL_error
extern "C" char aLuaMsg_00a56214[];
extern "C" int luaL_error(void* L, const char* fmt, ...);

// src: GUESS (confidence: low) [0x0075f860]
__declspec(naked) int LuaError_0075f860(void* L) {
    __asm {
        mov dword ptr [esp + 8], offset aLuaMsg_00a56214
        jmp luaL_error
    }
}
