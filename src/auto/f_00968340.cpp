// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to field_0x3c slot 0x4
// src: GUESS (confidence: low) [0x00968340]
__declspec(naked) void Thunk_00968340() {
    __asm {
        mov eax, dword ptr [esp + 0xc]
        mov ecx, dword ptr [eax + 0x3c]
        mov dword ptr [esp + 0xc], eax
        mov ecx, dword ptr [ecx + 0x4]
        jmp ecx
    }
}
