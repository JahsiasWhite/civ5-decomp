// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) dual virtual call pattern
class Host_008f42d0 {
public:
    // src: GUESS (confidence: high) [0x008f42d0]
    void __thiscall Dispatch();
};

__declspec(naked) void __thiscall Host_008f42d0::Dispatch() {
    __asm {
        push esi
        mov esi, ecx
        push edi
        mov edi, dword ptr [esi]
        mov eax, dword ptr [edi + 0x0c]
        call eax
        mov edx, dword ptr [edi + 0x10]
        push eax
        mov ecx, esi
        call edx
        pop edi
        pop esi
        ret
    }
}
