// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2

// src: GUESS (confidence: low) [0x00c9ed24]
extern int g_val_00c9ed24;

// src: GUESS (confidence: medium) [0x008a35a0]
void* AllocBlock_008a35a0(unsigned int size, int unused1, int unused2, unsigned int* heap)
{
    int v7 = 0;
    unsigned int v5 = 0;
    unsigned int v6 = 0;
    unsigned int* v3 = 0;
    unsigned int* v8 = 0;
    unsigned int v1;
    unsigned int* v2;
    unsigned int v4;

    v1 = (size + g_val_00c9ed24 - 1) & (g_val_00c9ed24 * -1);
    v6 = (((v1 + 0x10) + g_val_00c9ed24) + g_val_00c9ed24 + 7) & (g_val_00c9ed24 * -1);
    v3 = heap;
    while ((((int)(*v3 & 0x7fffffff) >> 30) == 1) == 0 && v7 == 0)
    {
        v5 = *v3 & 0x7fffffff;
        if ((((int)*v3 >> 31) == 0) != 0)
        {
            if (v5 == v6)
            {
                *v3 |= 0x80000000;
                v4 = (unsigned int)v3 + 4;
                v4 = (v4 + g_val_00c9ed24 - 1) & (g_val_00c9ed24 * -1);
                v8 = (unsigned int*)v4;
                v8[3] = (unsigned short)(v4 - (unsigned int)v3);
                v8[0] = v1;
                v8[2] = v4;
                v8[1] = v4 + 0x10;
                *(unsigned int*)(v8[1] + *(int*)(v8[1] - 0x10)) = *(unsigned int*)(v8[1] - 8);
                *(unsigned int*)(v8[1] + *(int*)(v8[1] - 0x10) + 4) = *(unsigned int*)(v8[1] - 0xc);
                v7 = 1;
            }
            else if (v5 > v6 + 0x10)
            {
                *v3 = v6;
                *v3 |= 0x80000000;
                v4 = (unsigned int)v3 + 4;
                v4 = (v4 + g_val_00c9ed24 - 1) & (g_val_00c9ed24 * -1);
                v8 = (unsigned int*)v4;
                v8[3] = (unsigned short)(v4 - (unsigned int)v3);
                v8[0] = v1;
                v8[2] = v4;
                v8[1] = v4 + 0x10;
                *(unsigned int*)(v8[1] + *(int*)(v8[1] - 0x10)) = *(unsigned int*)(v8[1] - 8);
                *(unsigned int*)(v8[1] + *(int*)(v8[1] - 0x10) + 4) = *(unsigned int*)(v8[1] - 0xc);
                v2 = (unsigned int*)((char*)v3 + v6 + 4);
                *v2 = v5 - v6 - 4;
                *v2 &= 0x7fffffff;
                v7 = 1;
            }
            else
            {
                v3 = (unsigned int*)((char*)v3 + v5 + 4);
            }
        }
        else
        {
            v3 = (unsigned int*)((char*)v3 + v5 + 4);
        }
    }
    if (v7)
    {
        return (void*)v8[1];
    }
    else
    {
        return 0;
    }
}
