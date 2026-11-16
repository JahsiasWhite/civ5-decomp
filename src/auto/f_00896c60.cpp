// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Od -/arch:SSE2
// src: GUESS (confidence: low) [0x00896c60]
void __cdecl SetFloat_00896c60(void* p, float val) {
    *(float*)((char*)p + 0x334) = val;
}
