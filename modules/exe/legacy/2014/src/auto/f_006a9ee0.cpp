// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x006cccf0
// src: GUESS (confidence: low) [0x006cccf0]
int Target_006cccf0();

// src: GUESS (confidence: medium) [0x006a9ee0]
__declspec(naked) void Thunk_006a9ee0() {
    __asm {
        push ecx
        mov eax, Target_006cccf0
        call eax
        pop ecx
        jmp eax
    }
}
