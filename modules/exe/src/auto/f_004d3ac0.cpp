// c5d-model: Gemini 4 Hydrogen
// c5d-review: dynamic resolver thunk returning float via x87 stack
extern "C" void Target_00527e40();
// src: GUESS (confidence: low) [0x004d3ac0]
__declspec(naked) float Thunk_004d3ac0() {
    __asm {
        mov eax, Target_00527e40
        call eax
        mov dword ptr [esp - 4], eax
        fld dword ptr [esp - 4]
        ret
    }
}
