// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline resolving target 0x004e1260
// src: GUESS (confidence: low) [0x004e1260]
int Target_004e1260();

// src: GUESS (confidence: medium) [0x0044d8c0]
__declspec(naked) void Thunk_0044d8c0() {
    __asm {
        push ecx
        mov eax, Target_004e1260
        call eax
        pop ecx
        jmp eax
    }
}
