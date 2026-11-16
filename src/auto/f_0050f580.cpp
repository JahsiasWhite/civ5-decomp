// c5d-model: Gemini 3.8 Flash
// c5d-review: Lua error thunk setting error string and tail-jumping to luaL_error
extern "C" char aDontCallThis_00a56380[];
extern "C" int luaL_error(void* L, const char* fmt, ...);

// src: GUESS (confidence: low) [0x0050f580]
__declspec(naked) int LuaError_0050f580(void* L) {
    __asm {
        mov dword ptr [esp + 8], offset aDontCallThis_00a56380
        jmp luaL_error
    }
}
