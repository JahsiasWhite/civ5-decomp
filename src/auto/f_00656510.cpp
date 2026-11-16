// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x005c1a80
// src: GUESS (confidence: low) [0x005c1a80]
int Target_005c1a80();

// src: GUESS (confidence: medium) [0x00656510]
__declspec(naked) int Thunk_00656510() {
    __asm {
        mov eax, Target_005c1a80
        call eax
        ret
    }
}
