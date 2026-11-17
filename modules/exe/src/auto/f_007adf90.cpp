// c5d-model: Gemini 4 Hydrogen
// c5d-review: dynamic resolver thunk returning float via x87 stack
extern "C" void Target_0053e870();
// src: GUESS (confidence: low) [0x007adf90]
__declspec(naked) float Thunk_007adf90() {
    __asm {
        mov eax, Target_0053e870
        call eax
        mov dword ptr [esp - 4], eax
        fld dword ptr [esp - 4]
        ret
    }
}
