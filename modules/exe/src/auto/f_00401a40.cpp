#include <stdlib.h>

// src: EXE [0x00cb1484]
extern void (__cdecl* g_freeHook_00cb1484)(void*);

// src: GUESS (confidence: high) [0x00401a40]
void FreeTagged_00401a40(void* p)
{
    if (!p)
        return;
    unsigned int tag = ((unsigned int*)p)[-1];
    if (tag & 1)
        free((void*)(tag - 1));
    else
        (*g_freeHook_00cb1484)((void*)tag);
}
