// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/O2 +/O1 +/Oy- +/hotpatch
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned int dwBytes);

class Heap_009278b2 {
public:
    int pad;
    void* m_hHeap;
    // src: GUESS (confidence: high) [0x009278b2]
    void* __thiscall Alloc(unsigned int bytes);
};

void* Heap_009278b2::Alloc(unsigned int bytes) {
    return HeapAlloc(m_hHeap, 0, bytes);
}
