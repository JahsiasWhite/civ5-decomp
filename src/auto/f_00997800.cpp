// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) conditional byte store
class Host_00997800 {
public:
    // src: GUESS (confidence: high) [0x00997800]
    bool __cdecl SetByte(unsigned int count, char val);
};

__declspec(naked) bool __cdecl Host_00997800::SetByte(unsigned int count, char val) {
    __asm {
        xor eax, eax
        cmp dword ptr [esp + 4], 1
        jbe loc_done
        mov al, byte ptr [esp + 8]
        mov byte ptr [ecx], al
        mov eax, 1
    loc_done:
        ret
    }
}
