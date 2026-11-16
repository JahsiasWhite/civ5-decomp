// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) dispatch table call
extern "C" void* g_dispatchTable_00cb73a4[];

class Host_009b55f0 {
public:
    // src: GUESS (confidence: high) [0x009b55f0]
    void __thiscall Dispatch();
};

__declspec(naked) void __thiscall Host_009b55f0::Dispatch() {
    __asm {
        mov eax, dword ptr [ecx + 4]
        movzx eax, byte ptr [eax]
        imul eax, eax, 0x34
        push ecx
        mov ecx, dword ptr [eax + 0x00cb73a4]
        call ecx
        add esp, 4
        ret
    }
}
