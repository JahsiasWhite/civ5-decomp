// Default small-object allocator configuration.
#include <windows.h>

struct FSmallObjectAllocatorInitParams
{
    // 0x0081ba00
    FSmallObjectAllocatorInitParams(unsigned int uiA, unsigned int uiB, unsigned int uiC,
                                    unsigned int uiD, unsigned int uiE, unsigned int uiF,
                                    bool bG, int iH, int iI);
    char _data[0x3c];
};

// 0x006f8d70, 67 bytes
extern "C" FSmallObjectAllocatorInitParams* GetSmallObjectAllocatorInitParams()
{
    static FSmallObjectAllocatorInitParams s_params(
        0x2000000, 0x2000000, 0x10000, 0x1000, 0x200, 0x20, true, 0, 0);
    return &s_params;
}
