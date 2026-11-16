// c5d-model: Gemini 4 Hydrogen
// c5d-review: dynamic resolver thunk returning float via x87 stack
extern "C" void Target_004b0f10();
// src: GUESS (confidence: low) [0x00577100]
__declspec(naked) float Thunk_00577100() {
    __asm {
        mov eax, Target_004b0f10
        call eax
        mov dword ptr [esp - 4], eax
        fld dword ptr [esp - 4]
        ret
    }
}
