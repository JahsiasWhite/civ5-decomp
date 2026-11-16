// c5d-model: Gemini 3.8 Flash
// c5d-review: Lua error thunk setting error string and tail-jumping to luaL_error
extern "C" char aLuaMsg_00a561b0[];
extern "C" int luaL_error(void* L, const char* fmt, ...);

// src: GUESS (confidence: low) [0x00669650]
__declspec(naked) int LuaError_00669650(void* L) {
    __asm {
        mov dword ptr [esp + 8], offset aLuaMsg_00a561b0
        jmp luaL_error
    }
}
