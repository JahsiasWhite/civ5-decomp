// c5d-model: Gemini 4 Hydrogen
// c5d-review: virtual tail-call thunk forwarding to vtable slot 5
// src: GUESS (confidence: low) [0x00945710]
__declspec(naked) void Thunk_00945710(void* p) {
    __asm {
        mov eax, dword ptr [esp + 4]
        mov ecx, dword ptr [eax]
        mov dword ptr [esp + 4], eax
        mov eax, dword ptr [ecx + 0x14]
        jmp eax
    }
}
