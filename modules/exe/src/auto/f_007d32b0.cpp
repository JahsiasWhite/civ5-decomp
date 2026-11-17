// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: +/Oy-
extern "C" {
    __declspec(dllimport) void* __stdcall GetProcessHeap(void);
    __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);
}

// src: GUESS (confidence: high) [0x007d32b0]
int __cdecl FreeHeapMem_007d32b0(int unused, void* mem) {
    return HeapFree(GetProcessHeap(), 0, mem);
}
