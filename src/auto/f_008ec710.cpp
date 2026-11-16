// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked branch structure for 0x008ec710

// src: GUESS (confidence: low) [0x008ec710]
__declspec(naked) int __fastcall GetField_008ec710(void* p)
{
    __asm {
        mov eax, dword ptr [ecx]
        sub eax, 2
        je loc_target
        sub eax, 1
        je loc_target
        sub eax, 1
    loc_target:
        mov eax, dword ptr [ecx + 4]
        ret
    }
}
