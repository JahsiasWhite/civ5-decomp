// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) table index lookup
// src: GUESS (confidence: high) [0x009bbc00]
__declspec(naked) int __cdecl Lookup_009bbc00(const int* host, int idx) {
    __asm {
        mov eax, dword ptr [esp + 8]
        mov ecx, dword ptr [esp + 4]
        cmp eax, dword ptr [ecx]
        jl loc_ok
        xor eax, eax
        ret
    loc_ok:
        shl eax, 6
        add eax, dword ptr [ecx + 4]
        ret
    }
}
