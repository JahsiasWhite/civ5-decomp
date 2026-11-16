// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to field_0x44 slot 0x4
// src: GUESS (confidence: low) [0x009459c0]
__declspec(naked) void Thunk_009459c0() {
    __asm {
        mov eax, dword ptr [esp + 0x4]
        mov ecx, dword ptr [eax + 0x44]
        mov dword ptr [esp + 0x4], eax
        mov edx, dword ptr [ecx + 0x4]
        jmp edx
    }
}
