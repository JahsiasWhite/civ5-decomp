// c5d-model: Gemini 3.8 Flash
// c5d-review: Lua error thunk setting error string and tail-jumping to luaL_error
extern "C" char aLuaMsg_00a56360[];
extern "C" int luaL_error(void* L, const char* fmt, ...);

// src: GUESS (confidence: low) [0x006a9030]
__declspec(naked) int LuaError_006a9030(void* L) {
    __asm {
        mov dword ptr [esp + 8], offset aLuaMsg_00a56360
        jmp luaL_error
    }
}
