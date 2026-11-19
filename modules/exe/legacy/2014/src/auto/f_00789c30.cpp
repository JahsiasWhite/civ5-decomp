// c5d-model: Gemini 3.8 Flash
// c5d-review: dynamic trampoline calling resolver
extern "C" void Target_00707e40();

// src: GUESS (confidence: low) [0x00789c30]
__declspec(naked) void Thunk_00789c30() {
    __asm {
        push ecx
        mov eax, Target_00707e40
        call eax
        pop ecx
        jmp eax
    }
}
