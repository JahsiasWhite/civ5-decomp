// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0040f260
// src: GUESS (confidence: low) [0x0040f260]
int Target_0040f260();

// src: GUESS (confidence: medium) [0x00724930]
__declspec(naked) int Thunk_00724930() {
    __asm {
        mov eax, Target_0040f260
        call eax
        ret
    }
}
