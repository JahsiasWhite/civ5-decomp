// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2
extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)
// src: GUESS (confidence: high) [0x009443e0]
void __cdecl ZeroFive_009443e0(int* arr) {
    memset(arr, 0, 20);
}
