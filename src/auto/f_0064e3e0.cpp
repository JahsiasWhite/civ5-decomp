// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x007418e0
// src: GUESS (confidence: low) [0x007418e0]
int Target_007418e0();

// src: GUESS (confidence: medium) [0x0064e3e0]
__declspec(naked) int Thunk_0064e3e0() {
    __asm {
        mov eax, Target_007418e0
        call eax
        ret
    }
}
