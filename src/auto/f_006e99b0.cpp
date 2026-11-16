// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline function calling 0x004f7310
// src: GUESS (confidence: low) [0x004f7310]
int Target_004f7310();

// src: GUESS (confidence: medium) [0x006e99b0]
__declspec(naked) int Thunk_006e99b0() {
    __asm {
        mov eax, Target_004f7310
        call eax
        ret
    }
}
