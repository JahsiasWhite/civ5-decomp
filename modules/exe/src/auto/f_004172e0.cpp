// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00435090
// src: GUESS (confidence: low) [0x00435090]
int Target_00435090();

// src: GUESS (confidence: medium) [0x004172e0]
__declspec(naked) int Thunk_004172e0() {
    __asm {
        mov eax, Target_00435090
        call eax
        ret
    }
}
