// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x00416cf0
// src: GUESS (confidence: low) [0x00416cf0]
int Target_00416cf0();

// src: GUESS (confidence: medium) [0x004173d0]
__declspec(naked) int Thunk_004173d0() {
    __asm {
        mov eax, Target_00416cf0
        call eax
        ret
    }
}
