// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Oy-
// src: GUESS (confidence: high) [0x00552450]
void __cdecl SwapBytes_00552450(unsigned char* a, unsigned char* b) {
    if (a != b) {
        unsigned char tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
