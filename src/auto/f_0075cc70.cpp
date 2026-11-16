// c5d-model: Gemini 3.8 Flash
// c5d-review: dynamic trampoline calling resolver
extern "C" void Target_00547ff0();

// src: GUESS (confidence: low) [0x0075cc70]
__declspec(naked) void Thunk_0075cc70() {
    __asm {
        push ecx
        mov eax, Target_00547ff0
        call eax
        pop ecx
        jmp eax
    }
}
