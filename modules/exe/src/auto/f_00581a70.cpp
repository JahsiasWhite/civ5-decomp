// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00581e70
// src: GUESS (confidence: low) [0x00581e70]
int Target_00581e70();

// src: GUESS (confidence: medium) [0x00581a70]
__declspec(naked) int Thunk_00581a70() {
    __asm {
        mov eax, Target_00581e70
        call eax
        ret
    }
}
