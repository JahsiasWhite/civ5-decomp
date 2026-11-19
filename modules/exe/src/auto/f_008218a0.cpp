// Looks up the entry for a block size (0x800 >> i, i < 10); 0 when the size
// isn't one of them.

// src: GUESS (confidence: low) [0x02ea0fe0]
extern int g_sizeTable_02ea0fe0[10];

// src: GUESS (confidence: low) [0x008bb7e0]
int __stdcall LookupBySize_008bb7e0(int size)
{
    unsigned int i;
    for (i = 0; i < 10; ++i)
    {
        if ((unsigned int)size == (0x800u >> i))
            break;
    }
    if (i == 10)
        return 0;
    return g_sizeTable_02ea0fe0[i];
}
