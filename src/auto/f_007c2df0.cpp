// c5d-model: Gemini 3.8 Flash
// c5d-review: delegate call jumping to [this + 0x10] with this = [this + 0xc]
// src: GUESS (confidence: low) [0x007c2df0]
__declspec(naked) void DelegateCall_007c2df0() {
    __asm {
        push ebp
        mov ebp, esp
        mov eax, ecx
        mov ecx, dword ptr [eax + 0xc]
        mov edx, dword ptr [eax + 0x10]
        pop ebp
        jmp edx
    }
}
