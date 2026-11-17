// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00699d50
// src: GUESS (confidence: low) [0x00699d50]
int Target_00699d50();

// src: GUESS (confidence: medium) [0x00487720]
__declspec(naked) int Thunk_00487720() {
    __asm {
        mov eax, Target_00699d50
        call eax
        ret
    }
}
