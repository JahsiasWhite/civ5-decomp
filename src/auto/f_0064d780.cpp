// c5d-model: Gemini 4 Hydrogen
// c5d-review: thunk reading 2nd arg + 4 and tail-jumping to lua_pushinteger
extern "C" void lua_pushinteger(void* L, int n);
// src: GUESS (confidence: low) [0x0064d780]
__declspec(naked) void Thunk_0064d780(void* L, int* pVal) {
    __asm {
        mov eax, dword ptr [esp + 8]
        mov ecx, dword ptr [eax + 4]
        mov dword ptr [esp + 8], ecx
        jmp lua_pushinteger
    }
}
