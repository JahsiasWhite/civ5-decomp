// c5d-model: Gemini 3.8 Flash
// c5d-cflags: +/Od
// src: GUESS (confidence: low) [0x008a8580]
int __cdecl GetFlag_008a8580(void* p) {
    return *(int*)((char*)p + 0x20) & 1;
}
