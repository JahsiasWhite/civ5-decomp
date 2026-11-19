// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x007b2750
// src: GUESS (confidence: low) [0x007b2750]
int Target_007b2750();

// src: GUESS (confidence: medium) [0x005266b0]
__declspec(naked) void Thunk_005266b0() {
    __asm {
        push ecx
        mov eax, Target_007b2750
        call eax
        pop ecx
        jmp eax
    }
}
