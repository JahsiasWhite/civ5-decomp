// c5d-model: Gemini 3.8 Flash
// c5d-review: thunk dereferencing second argument and tail-jumping to lua_pushinteger
extern "C" void lua_pushinteger(void* L, int n);

// src: GUESS (confidence: low) [0x00459da0]
__declspec(naked) void Thunk_00459da0(void* L, int* pVal) {
    __asm {
        mov eax, dword ptr [esp + 8]
        mov ecx, dword ptr [eax]
        mov dword ptr [esp + 8], ecx
        jmp lua_pushinteger
    }
}
