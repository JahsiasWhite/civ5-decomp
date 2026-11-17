// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00573ba0
// src: GUESS (confidence: low) [0x00573ba0]
int Target_00573ba0();

// src: GUESS (confidence: medium) [0x0061fc40]
__declspec(naked) int Thunk_0061fc40() {
    __asm {
        mov eax, Target_00573ba0
        call eax
        ret
    }
}
