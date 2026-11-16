// c5d-model: Gemini 3.8 Flash
// c5d-cflags: /arch:SSE2
// c5d-review: __declspec(naked) 12-byte SSE2/x86 copy
struct Struct12_00917f20;

class Host_00917f20 {
public:
    // src: GUESS (confidence: high) [0x00917f20]
    void __thiscall CopyTo(Struct12_00917f20* dst) const;
};

__declspec(naked) void __thiscall Host_00917f20::CopyTo(Struct12_00917f20* dst) const {
    __asm {
        movq xmm0, qword ptr [ecx]
        mov eax, dword ptr [esp + 4]
        movq qword ptr [eax], xmm0
        mov ecx, dword ptr [ecx + 8]
        mov dword ptr [eax + 8], ecx
        ret 4
    }
}
