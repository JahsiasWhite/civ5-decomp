// c5d-model: Gemini 3.8 Flash
// c5d-review: hotpatch-compatible virtual call thunk forwarding to [this+4]->vtable[1]
// src: GUESS (confidence: low) [0x009279ad]
__declspec(naked) void Thunk_009279ad() {
    __asm {
        mov edi, edi
        push ebp
        mov ebp, esp
        mov ecx, dword ptr [ecx + 4]
        mov eax, dword ptr [ecx]
        pop ebp
        jmp dword ptr [eax + 4]
    }
}
