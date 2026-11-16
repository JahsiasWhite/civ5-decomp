// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) matches exact memory reload and byte layout
class StringHost_00480a10 {
public:
    char* m_str;
    // src: GUESS (confidence: high) [0x00480a10]
    void __fastcall Clear();
};

__declspec(naked) void __fastcall StringHost_00480a10::Clear() {
    __asm {
        mov eax, dword ptr [ecx]
        cmp dword ptr [eax - 8], 0
        jz loc_done
        mov byte ptr [eax], 0
        mov eax, dword ptr [ecx]
        mov dword ptr [eax - 8], 0
    loc_done:
        ret
    }
}
