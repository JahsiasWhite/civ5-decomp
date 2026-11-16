// c5d-model: Gemini 4 Hydrogen
// c5d-review: MSVC tail-call optimizes indirect call unless prevented
extern "C" void* g_fn_00ca37d0;
// src: GUESS (confidence: low) [0x0093b960]
__declspec(naked) void Call_0093b960(void* p) {
    __asm {
        mov eax, dword ptr [esp + 4]
        push eax
        call dword ptr [g_fn_00ca37d0]
        add esp, 4
        ret
    }
}
