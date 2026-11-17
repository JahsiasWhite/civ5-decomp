// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x00675d80
// src: GUESS (confidence: low) [0x00675d80]
int Target_00675d80();

// src: GUESS (confidence: medium) [0x00574c00]
__declspec(naked) void Thunk_00574c00() {
    __asm {
        push ecx
        mov eax, Target_00675d80
        call eax
        pop ecx
        jmp eax
    }
}
