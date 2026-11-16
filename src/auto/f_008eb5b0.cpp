// c5d-model: Gemini 3.8 Flash
// c5d-review: virtual call thunk forwarding to field_0x28c vtable slot 6
// src: GUESS (confidence: low) [0x008eb5b0]
__declspec(naked) void Thunk_008eb5b0() {
    __asm {
        mov ecx, dword ptr [ecx + 0x28c]
        mov eax, dword ptr [ecx]
        mov eax, dword ptr [eax + 0x18]
        jmp eax
    }
}
