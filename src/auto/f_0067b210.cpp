// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00684290
// src: GUESS (confidence: low) [0x00684290]
int Target_00684290();

// src: GUESS (confidence: medium) [0x0067b210]
__declspec(naked) int Thunk_0067b210() {
    __asm {
        mov eax, Target_00684290
        call eax
        ret
    }
}
