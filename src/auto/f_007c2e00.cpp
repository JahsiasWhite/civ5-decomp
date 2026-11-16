// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) callback invocation
class Host_007c2e00 {
public:
    // src: GUESS (confidence: high) [0x007c2e00]
    void __thiscall InvokeCallback(int a, int b, int c, int d);
};

__declspec(naked) void __thiscall Host_007c2e00::InvokeCallback(int a, int b, int c, int d) {
    __asm {
        push ebp
        mov ebp, esp
        mov eax, ecx
        mov ecx, dword ptr [ebp + 8]
        mov edx, dword ptr [eax + 0x10]
        push ecx
        mov ecx, dword ptr [eax + 0xc]
        call edx
        pop ebp
        ret 0x10
    }
}
