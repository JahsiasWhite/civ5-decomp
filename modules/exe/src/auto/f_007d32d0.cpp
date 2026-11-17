// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
#include <windows.h>

// Allocator callback: allocates size bytes from the process heap; the
// first argument (user context) is unused. Returns NULL for zero size.
void* ProcessHeapAllocCallback(void* /*context*/, SIZE_T size)
{
    if (size == 0)
        return 0;
    return HeapAlloc(GetProcessHeap(), 0, size);
}
