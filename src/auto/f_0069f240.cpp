// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x00447230
// src: GUESS (confidence: low) [0x00447230]
int Target_00447230();

// src: GUESS (confidence: medium) [0x0069f240]
__declspec(naked) void Thunk_0069f240() {
    __asm {
        push ecx
        mov eax, Target_00447230
        call eax
        pop ecx
        jmp eax
    }
}
