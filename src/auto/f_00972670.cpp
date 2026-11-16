// c5d-model: Gemini 4 Hydrogen
// c5d-review: MSVC 2008 emits movsx/movzx+neg eax instead of mov al+neg al
extern "C" char g_str_0606e9b0[];
// src: GUESS (confidence: low) [0x00972670]
__declspec(naked) char* GetStr_00972670() {
    __asm {
        mov al, byte ptr [g_str_0606e9b0]
        neg al
        sbb eax, eax
        and eax, offset g_str_0606e9b0
        ret
    }
}
