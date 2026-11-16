// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) zero 5 dwords
// src: GUESS (confidence: high) [0x009443e0]
__declspec(naked) void __cdecl ZeroFive_009443e0(int* arr) {
    __asm {
        mov ecx, dword ptr [esp + 4]
        xor eax, eax
        mov dword ptr [ecx], eax
        mov dword ptr [ecx + 4], eax
        mov dword ptr [ecx + 8], eax
        mov dword ptr [ecx + 0xc], eax
        mov dword ptr [ecx + 0x10], eax
        ret
    }
}
