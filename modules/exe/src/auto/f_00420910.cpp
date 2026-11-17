// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x0049abf0
// src: GUESS (confidence: low) [0x0049abf0]
int Target_0049abf0();

// src: GUESS (confidence: medium) [0x00420910]
__declspec(naked) int Thunk_00420910() {
    __asm {
        mov eax, Target_0049abf0
        call eax
        ret
    }
}
