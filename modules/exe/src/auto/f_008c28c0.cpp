// Under the global spin lock, reads how much of the 128 KB pool is free.

#include <windows.h>

// src: GUESS (confidence: low) [0x030bce00]
extern volatile LONG g_poolLock_030bce00;
// src: GUESS (confidence: low) [0x0413e2b8]
extern int g_poolTop_0413e2b8;
// src: GUESS (confidence: low) [0x030bce40]
extern int g_poolBase_030bce40;

// src: GUESS (confidence: low) [0x008c28c0]
int GetPoolFree_008c28c0()
{
    while (InterlockedCompareExchange(&g_poolLock_030bce00, 1, 0) == 1)
        ;
    int used = g_poolTop_0413e2b8 - g_poolBase_030bce40;
    g_poolLock_030bce00 = 0;
    return used + 0x20000;
}
