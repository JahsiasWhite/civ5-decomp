// c5d-cflags: -/O2 +/O1 +/Oy- +/hotpatch
// src: SDK [0x009d63f8]
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);

// Same heap wrapper as Heap_009278b2 (slot 0) and Heap_00927920 (slot 3).
// src: GUESS (confidence: high) [0x009278c9]
class Heap_009278c9 {
public:
    int pad;
    void* m_hHeap;
    // src: GUESS (confidence: high) [0x009278c9]
    void Free(void* mem);
};

void Heap_009278c9::Free(void* mem) {
    if (mem)
        HeapFree(m_hHeap, 0, mem);
}
