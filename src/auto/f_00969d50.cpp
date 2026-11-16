// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) atomic swap element
// src: GUESS (confidence: high) [0x00969d50]
__declspec(naked) int __cdecl Exchange_00969d50(const int* offset_ptr, int new_val, const int* base_ptr) {
    __asm {
        mov eax, dword ptr [esp + 0x0c]
        mov ecx, dword ptr [eax + 4]
        mov edx, dword ptr [esp + 4]
        add ecx, dword ptr [edx]
        mov edx, dword ptr [esp + 8]
        mov eax, dword ptr [ecx]
        mov dword ptr [ecx], edx
        ret
    }
}
