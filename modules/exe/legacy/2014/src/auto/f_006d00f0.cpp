// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00711cd0
// src: GUESS (confidence: low) [0x00711cd0]
int Target_00711cd0();

// src: GUESS (confidence: medium) [0x006d00f0]
__declspec(naked) int Thunk_006d00f0() {
    __asm {
        mov eax, Target_00711cd0
        call eax
        ret
    }
}
