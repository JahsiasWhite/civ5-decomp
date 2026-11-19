// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x0074f610
// src: GUESS (confidence: low) [0x0074f610]
int Target_0074f610();

// src: GUESS (confidence: medium) [0x0052c350]
__declspec(naked) void Thunk_0052c350() {
    __asm {
        push ecx
        mov eax, Target_0074f610
        call eax
        pop ecx
        jmp eax
    }
}
