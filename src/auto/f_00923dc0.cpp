// c5d-model: Gemini 4 Hydrogen
// c5d-review: intentional null pointer write stub (reads 2nd arg into edi)
// src: GUESS (confidence: low) [0x00923dc0]
__declspec(naked) void NullCrash_00923dc0(int a, int b) {
    __asm {
        push edi
        mov ecx, dword ptr [esp + 8]
        mov edi, dword ptr [esp + 0xc]
        xor eax, eax
        mov dword ptr [eax], ecx
        pop edi
        ret
    }
}
