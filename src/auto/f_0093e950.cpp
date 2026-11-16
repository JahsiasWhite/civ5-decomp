// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to field_0x8 slot 0x8
// src: GUESS (confidence: low) [0x0093e950]
__declspec(naked) void Thunk_0093e950() {
    __asm {
        mov eax, dword ptr [esp + 0x10]
        mov ecx, dword ptr [eax + 0x8]
        mov dword ptr [esp + 0x10], eax
        mov ecx, dword ptr [ecx + 0x8]
        jmp ecx
    }
}
