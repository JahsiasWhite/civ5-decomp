// c5d-model: Gemini 4 Hydrogen
// c5d-review: dynamic resolver thunk returning float via x87 stack
extern "C" void Target_004855c0();
// src: GUESS (confidence: low) [0x006f6e00]
__declspec(naked) float Thunk_006f6e00() {
    __asm {
        mov eax, Target_004855c0
        call eax
        mov dword ptr [esp - 4], eax
        fld dword ptr [esp - 4]
        ret
    }
}
