// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0061ee60
// src: GUESS (confidence: low) [0x0061ee60]
int Target_0061ee60();

// src: GUESS (confidence: medium) [0x0057b4c0]
__declspec(naked) int Thunk_0057b4c0() {
    __asm {
        mov eax, Target_0061ee60
        call eax
        ret
    }
}
