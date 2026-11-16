// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) bitwise and member arithmetic
class Host_008eb210 {
public:
    // src: GUESS (confidence: high) [0x008eb210]
    int __thiscall CalcValue() const;
};

__declspec(naked) int __thiscall Host_008eb210::CalcValue() const {
    __asm {
        mov edx, dword ptr [ecx + 0x5c]
        mov eax, dword ptr [edx + 0x54]
        sub eax, dword ptr [edx + 0x50]
        add edx, 0x4c
        sar eax, 4
        shl eax, 4
        add eax, dword ptr [ecx + 0x48]
        ret
    }
}
