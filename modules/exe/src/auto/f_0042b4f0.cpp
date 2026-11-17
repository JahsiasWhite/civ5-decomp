// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x006ab570
// src: GUESS (confidence: low) [0x006ab570]
int Target_006ab570();

// src: GUESS (confidence: medium) [0x0042b4f0]
__declspec(naked) void Thunk_0042b4f0() {
    __asm {
        push ecx
        mov eax, Target_006ab570
        call eax
        pop ecx
        jmp eax
    }
}
