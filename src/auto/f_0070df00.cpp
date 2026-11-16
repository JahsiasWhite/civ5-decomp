// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0050d470
// src: GUESS (confidence: low) [0x0050d470]
int Target_0050d470();

// src: GUESS (confidence: medium) [0x0070df00]
__declspec(naked) int Thunk_0070df00() {
    __asm {
        mov eax, Target_0050d470
        call eax
        ret
    }
}
