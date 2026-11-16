// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0058fe90
// src: GUESS (confidence: low) [0x0058fe90]
int Target_0058fe90();

// src: GUESS (confidence: medium) [0x00528c80]
__declspec(naked) int Thunk_00528c80() {
    __asm {
        mov eax, Target_0058fe90
        call eax
        ret
    }
}
