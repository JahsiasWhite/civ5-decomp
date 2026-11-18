// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// Frees a block allocated with a header: the word before the block holds the
// underlying allocation, tagged in bit 0 when it came from the CRT heap.

#include <stdlib.h>

// src: GUESS (confidence: low) [0x00cb1484]
extern void (__cdecl *g_freeHook_00cb1484)(void* p);

// src: GUESS (confidence: low) [0x00b84464]
class Allocator_007c2f90
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    // src: GUESS (confidence: low) [0x007c2f90]
    virtual void Free(void* block, unsigned int size);
};

void Allocator_007c2f90::Free(void* block, unsigned int size)
{
    if (block)
    {
        unsigned int base = ((unsigned int*)block)[-1];
        if (base & 1)
            free((void*)(base - 1));
        else
            g_freeHook_00cb1484((void*)base);
    }
}
