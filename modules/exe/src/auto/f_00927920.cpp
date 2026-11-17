// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/O2 +/O1 +/Oy- +/hotpatch
extern "C" __declspec(dllimport) unsigned int __stdcall HeapSize(void* hHeap, unsigned long dwFlags, const void* lpMem);

class Heap_00927920 {
public:
    int pad;
    void* m_hHeap;
    // src: GUESS (confidence: high) [0x00927920]
    unsigned int __thiscall Size(const void* mem);
};

unsigned int Heap_00927920::Size(const void* mem) {
    return HeapSize(m_hHeap, 0, mem);
}
