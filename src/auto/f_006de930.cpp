// c5d-model: Gemini 3.8 Flash
// c5d-review: obfuscated/encoded address thunk
extern "C" char g_ref_009f2c0c;
extern "C" char g_ref_00495f10;

// src: GUESS (confidence: low) [0x006de930]
__declspec(naked) void* Decode_006de930() {
    __asm {
        mov eax, offset g_ref_009f2c0c
        xor eax, offset g_ref_00495f10
        ret
    }
}
