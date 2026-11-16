// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to field_0x8 slot 0x50
// src: GUESS (confidence: low) [0x00927cb0]
__declspec(naked) void Thunk_00927cb0() {
    __asm {
        mov eax, dword ptr [esp + 0x4]
        mov ecx, dword ptr [eax + 0x8]
        mov dword ptr [esp + 0x4], eax
        mov edx, dword ptr [ecx + 0x50]
        jmp edx
    }
}
