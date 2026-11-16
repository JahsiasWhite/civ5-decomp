// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked backward jump loop for 0x009183a0

// src: GUESS (confidence: low) [0x009183a0]
__declspec(naked) char __fastcall FindNode_009183a0(void* p)
{
    __asm {
        mov al, byte ptr [ecx + 0x18]
        mov ecx, dword ptr [ecx + 0x14]
        test ecx, ecx
        je loc_ret
        test al, al
        jne loc_ret
        _emit 0xe9
        _emit 0xed
        _emit 0xff
        _emit 0xff
        _emit 0xff
    loc_ret:
        ret
    }
}
