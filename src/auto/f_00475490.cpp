// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x005f2d90
// src: GUESS (confidence: low) [0x005f2d90]
int Target_005f2d90();

// src: GUESS (confidence: medium) [0x00475490]
__declspec(naked) int Thunk_00475490() {
    __asm {
        mov eax, Target_005f2d90
        call eax
        ret
    }
}
