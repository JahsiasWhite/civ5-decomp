// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x004f5cd0
// src: GUESS (confidence: low) [0x004f5cd0]
int Target_004f5cd0();

// src: GUESS (confidence: medium) [0x0079e870]
__declspec(naked) int Thunk_0079e870() {
    __asm {
        mov eax, Target_004f5cd0
        call eax
        ret
    }
}
