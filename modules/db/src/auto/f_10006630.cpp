// src: EXE [0x10006630]
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low)
extern HANDLE g_hHeap_1061b6c4;
// src: GUESS (confidence: low)
extern DWORD g_dwHeapAllocatedBytes_1061b6d0;
// src: GUESS (confidence: low)
extern DWORD g_dwHeapCommittedBytes_1061b6d4;
// src: GUESS (confidence: low)
extern DWORD g_dwHeapOverheadBytes_1061b6d8;
// src: GUESS (confidence: low)
extern DWORD g_dwHeapUncommittedBytes_1061b6dc;
// src: GUESS (confidence: low)
extern DWORD g_dwHeapRegions_1061b6e0;

// src: GUESS (confidence: low)
void UpdateHeapStats_10006630() {
    g_dwHeapRegions_1061b6e0 = 0;
    g_dwHeapAllocatedBytes_1061b6d0 = 0;
    g_dwHeapOverheadBytes_1061b6d8 = 0;
    g_dwHeapCommittedBytes_1061b6d4 = 0;
    g_dwHeapUncommittedBytes_1061b6dc = 0;

    if (HeapLock(g_hHeap_1061b6c4)) {
        PROCESS_HEAP_ENTRY entry;
        entry.lpData = 0;
        while (HeapWalk(g_hHeap_1061b6c4, &entry)) {
            if (entry.wFlags & PROCESS_HEAP_ENTRY_BUSY) {
                g_dwHeapAllocatedBytes_1061b6d0 += entry.cbData;
                g_dwHeapOverheadBytes_1061b6d8 += entry.cbOverhead;
            } else if (entry.wFlags & PROCESS_HEAP_REGION) {
                ++g_dwHeapRegions_1061b6e0;
                g_dwHeapCommittedBytes_1061b6d4 += entry.Region.dwCommittedSize;
                g_dwHeapUncommittedBytes_1061b6dc += entry.Region.dwUnCommittedSize;
                g_dwHeapOverheadBytes_1061b6d8 += entry.cbOverhead;
            }
        }
        HeapUnlock(g_hHeap_1061b6c4);
    }
}
