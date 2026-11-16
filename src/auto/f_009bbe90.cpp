// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) copy 8 bytes to globals
extern "C" {
    extern int g_val_0606fc00;
    extern int g_val_0606fc04;
}

// src: GUESS (confidence: high) [0x009bbe90]
__declspec(naked) void __cdecl SetGlobals_009bbe90(const int* src) {
    __asm {
        mov eax, dword ptr [esp + 4]
        mov ecx, dword ptr [eax]
        mov edx, dword ptr [eax + 4]
        mov dword ptr [g_val_0606fc00], ecx
        mov dword ptr [g_val_0606fc04], edx
        ret
    }
}
