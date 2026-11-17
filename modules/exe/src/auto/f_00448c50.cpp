// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0041ce40
// src: GUESS (confidence: low) [0x0041ce40]
int Target_0041ce40();

// src: GUESS (confidence: medium) [0x00448c50]
__declspec(naked) int Thunk_00448c50() {
    __asm {
        mov eax, Target_0041ce40
        call eax
        ret
    }
}
