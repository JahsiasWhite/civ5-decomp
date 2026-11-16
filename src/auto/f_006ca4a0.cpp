// c5d-model: Gemini 3.8 Flash
// c5d-review: dynamic trampoline calling resolver
extern "C" void Target_00530900();

// src: GUESS (confidence: low) [0x006ca4a0]
__declspec(naked) void Thunk_006ca4a0() {
    __asm {
        push ecx
        mov eax, Target_00530900
        call eax
        pop ecx
        jmp eax
    }
}
