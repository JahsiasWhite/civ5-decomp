// c5d-model: Gemini 3.8 Flash
// c5d-review: Naked trampoline for indirect call 0x00ca37d8

// src: EXE [0x00ca37d8]
extern "C" void* g_fn_00ca37d8;

// src: GUESS (confidence: low) [0x0093b970]
__declspec(naked) void Call_0093b970(void* p, unsigned int sz)
{
    __asm {
        mov eax, dword ptr [esp + 8]
        mov ecx, dword ptr [esp + 4]
        push eax
        push ecx
        call dword ptr [g_fn_00ca37d8]
        add esp, 8
        ret
    }
}
