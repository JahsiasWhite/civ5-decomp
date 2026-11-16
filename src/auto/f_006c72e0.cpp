// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00515270
// src: GUESS (confidence: low) [0x00515270]
int Target_00515270();

// src: GUESS (confidence: medium) [0x006c72e0]
__declspec(naked) int Thunk_006c72e0() {
    __asm {
        mov eax, Target_00515270
        call eax
        ret
    }
}
