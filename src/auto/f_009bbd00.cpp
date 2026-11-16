// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) indirect call with string and line
extern "C" {
    extern const char aGrannyMeshBindingCpp_00b743a0[];
    extern void* g_iGlobalB_00cb38b4;
}

// src: GUESS (confidence: high) [0x009bbd00]
__declspec(naked) void __cdecl Assert_009bbd00(void* arg) {
    __asm {
        mov eax, dword ptr [esp + 4]
        push eax
        push 0x3d
        push offset aGrannyMeshBindingCpp_00b743a0
        call dword ptr [g_iGlobalB_00cb38b4]
        add esp, 0x0c
        ret
    }
}
