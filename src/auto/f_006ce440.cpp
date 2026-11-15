// c5d-model: claude-opus-5-5
#include <windows.h>

// Heap used by the tracked allocator below.
HANDLE g_hTrackedAllocHeap;
// Peak number of bytes ever held by the tracked allocator.
SIZE_T g_uTrackedAllocPeakBytes;
// Number of bytes currently held by the tracked allocator.
SIZE_T g_uTrackedAllocCurBytes;

// lua_Alloc-style allocator: frees when nsize is 0, otherwise allocates or
// reallocates, keeping running and peak byte counts.
void* TrackedHeapAlloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    void* pResult = NULL;
    if (nsize == 0)
    {
        if (ptr != NULL)
        {
            g_uTrackedAllocCurBytes -= HeapSize(g_hTrackedAllocHeap, 0, ptr);
            if (g_uTrackedAllocCurBytes > g_uTrackedAllocPeakBytes)
                g_uTrackedAllocPeakBytes = g_uTrackedAllocCurBytes;
        }
        HeapFree(g_hTrackedAllocHeap, 0, ptr);
    }
    else if (ptr == NULL)
    {
        pResult = HeapAlloc(g_hTrackedAllocHeap, 0, nsize);
        g_uTrackedAllocCurBytes += nsize;
        if (g_uTrackedAllocCurBytes > g_uTrackedAllocPeakBytes)
            g_uTrackedAllocPeakBytes = g_uTrackedAllocCurBytes;
    }
    else
    {
        g_uTrackedAllocCurBytes += nsize - HeapSize(g_hTrackedAllocHeap, 0, ptr);
        if (g_uTrackedAllocCurBytes > g_uTrackedAllocPeakBytes)
            g_uTrackedAllocPeakBytes = g_uTrackedAllocCurBytes;
        pResult = HeapReAlloc(g_hTrackedAllocHeap, 0, ptr, nsize);
    }
    return pResult;
}
