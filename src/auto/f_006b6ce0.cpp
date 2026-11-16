// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x0049c040
// src: GUESS (confidence: low) [0x0049c040]
int Target_0049c040();

// src: GUESS (confidence: medium) [0x006b6ce0]
__declspec(naked) void Thunk_006b6ce0() {
    __asm {
        push ecx
        mov eax, Target_0049c040
        call eax
        pop ecx
        jmp eax
    }
}
