// c5d-model: Gemini 3.8 Flash
// c5d-review: virtual call thunk forwarding to field_8 vtable slot 0x60
struct Target_00927cc0;
struct Object_00927cc0 {
    char pad[8];
    Target_00927cc0* target;
};

// src: GUESS (confidence: low) [0x00927cc0]
__declspec(naked) void CallSlot60_00927cc0(Object_00927cc0* obj) {
    __asm {
        mov eax, [esp + 4]
        mov ecx, [eax + 8]
        mov edx, [ecx + 0x60]
        jmp edx
    }
}
