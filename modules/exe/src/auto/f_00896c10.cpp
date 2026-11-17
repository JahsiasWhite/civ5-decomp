// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Od -/arch:SSE2
// src: GUESS (confidence: low) [0x00896c10]
void __cdecl SetFloat_00896c10(void* p, float val) {
    *(float*)((char*)p + 0x330) = val;
}
