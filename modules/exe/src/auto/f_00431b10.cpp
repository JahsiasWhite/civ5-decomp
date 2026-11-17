// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0055baf0
// src: GUESS (confidence: low) [0x0055baf0]
int Target_0055baf0();

// src: GUESS (confidence: medium) [0x00431b10]
__declspec(naked) int Thunk_00431b10() {
    __asm {
        mov eax, Target_0055baf0
        call eax
        ret
    }
}
