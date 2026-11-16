// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x00404810
// src: GUESS (confidence: low) [0x00404810]
int Target_00404810();

// src: GUESS (confidence: medium) [0x0062ae40]
__declspec(naked) void Thunk_0062ae40() {
    __asm {
        push ecx
        mov eax, Target_00404810
        call eax
        pop ecx
        jmp eax
    }
}
