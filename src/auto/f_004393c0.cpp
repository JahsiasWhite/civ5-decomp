// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x005038e0
// src: GUESS (confidence: low) [0x005038e0]
int Target_005038e0();

// src: GUESS (confidence: medium) [0x004393c0]
__declspec(naked) int Thunk_004393c0() {
    __asm {
        mov eax, Target_005038e0
        call eax
        ret
    }
}
