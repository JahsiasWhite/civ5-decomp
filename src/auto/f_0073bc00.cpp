// c5d-model: Gemini 3.8 Flash
// c5d-review: interface adjustor thunk: adjusts this pointer and tail-calls vtable slot 2

// src: GUESS (confidence: low) [0x0073bc00]
__declspec(naked) void AdjustorThunk_0073bc00() {
    __asm {
        mov eax, [ecx + 4]
        mov eax, [eax + 8]
        add ecx, 4
        jmp eax
    }
}
