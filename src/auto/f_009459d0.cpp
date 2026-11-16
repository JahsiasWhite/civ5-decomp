// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to field_0x44 slot 0x8
// src: GUESS (confidence: low) [0x009459d0]
__declspec(naked) void Thunk_009459d0() {
    __asm {
        mov eax, dword ptr [esp + 0xc]
        mov ecx, dword ptr [eax + 0x44]
        mov dword ptr [esp + 0xc], eax
        mov ecx, dword ptr [ecx + 0x8]
        jmp ecx
    }
}
