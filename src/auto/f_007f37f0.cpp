// c5d-model: Gemini 3.8 Flash
// c5d-review: prologue stub falling through to 0x007f37fe

// src: GUESS (confidence: low) [0x007f37f0]
__declspec(naked) void Stub_007f37f0() {
    __asm {
        push ecx
        mov eax, dword ptr [esp + 8]
        mov ecx, dword ptr [eax + 0x2c]
        push ebx
        mov ebx, dword ptr [esp + 0x14]
        push ebp
    }
}
