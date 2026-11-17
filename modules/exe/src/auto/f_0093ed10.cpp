// c5d-model: Gemini 3.8 Flash
extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);

// src: GUESS (confidence: high) [0x0093ed10]
void __cdecl ClearBuffer_0093ed10(void* buf) {
    memset(buf, 0, 0x8c);
}
