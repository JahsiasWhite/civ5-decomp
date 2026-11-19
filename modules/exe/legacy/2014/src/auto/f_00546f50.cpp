// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x004a6c70
// src: GUESS (confidence: low) [0x004a6c70]
int Target_004a6c70();

// src: GUESS (confidence: medium) [0x00546f50]
__declspec(naked) int Thunk_00546f50() {
    __asm {
        mov eax, Target_004a6c70
        call eax
        ret
    }
}
