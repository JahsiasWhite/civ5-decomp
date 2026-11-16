// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to field_0x3c slot 0xc
// src: GUESS (confidence: low) [0x00968360]
__declspec(naked) void Thunk_00968360() {
    __asm {
        mov eax, dword ptr [esp + 0x10]
        mov ecx, dword ptr [eax + 0x3c]
        mov dword ptr [esp + 0x10], eax
        mov eax, dword ptr [ecx + 0xc]
        jmp eax
    }
}
