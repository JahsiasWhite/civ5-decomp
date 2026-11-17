// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x006ab0e0
// src: GUESS (confidence: low) [0x006ab0e0]
int Target_006ab0e0();

// src: GUESS (confidence: medium) [0x006726e0]
__declspec(naked) int Thunk_006726e0() {
    __asm {
        mov eax, Target_006ab0e0
        call eax
        ret
    }
}
