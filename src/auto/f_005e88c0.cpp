// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) indirect virtual call
class Host_005e88c0 {
public:
    // src: GUESS (confidence: high) [0x005e88c0]
    void __thiscall VirtualCall(int arg);
};

__declspec(naked) void __thiscall Host_005e88c0::VirtualCall(int arg) {
    __asm {
        mov ecx, dword ptr [ecx]
        test ecx, ecx
        je loc_done
        mov eax, dword ptr [ecx]
        mov edx, dword ptr [esp + 4]
        mov eax, dword ptr [eax + 0x4c]
        push 1
        push edx
        call eax
    loc_done:
        ret 4
    }
}
