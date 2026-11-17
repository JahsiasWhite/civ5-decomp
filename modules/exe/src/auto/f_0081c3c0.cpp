// c5d-model: Gemini 4 Hydrogen
// c5d-review: EFLAGS ID bit check requires pushfd/popfd inline assembly
// src: GUESS (confidence: high) [0x0081c3c0]
__declspec(naked) bool CheckCPUID_0081c3c0() {
    __asm {
        pushfd
        pop eax
        xor eax, 0x200000
        push eax
        popfd
        pushfd
        pop edx
        xor eax, edx
        sete al
        ret
    }
}
