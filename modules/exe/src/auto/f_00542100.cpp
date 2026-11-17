// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x004cc9a0
// src: GUESS (confidence: low) [0x004cc9a0]
int Target_004cc9a0();

// src: GUESS (confidence: medium) [0x00542100]
__declspec(naked) void Thunk_00542100() {
    __asm {
        push ecx
        mov eax, Target_004cc9a0
        call eax
        pop ecx
        jmp eax
    }
}
