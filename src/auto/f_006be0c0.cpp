// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0072b0e0
// src: GUESS (confidence: low) [0x0072b0e0]
int Target_0072b0e0();

// src: GUESS (confidence: medium) [0x006be0c0]
__declspec(naked) int Thunk_006be0c0() {
    __asm {
        mov eax, Target_0072b0e0
        call eax
        ret
    }
}
