// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low) [0x06028940]
extern void* g_slots_007f98b0[32];

// src: GUESS (confidence: high) [0x007f98b0]
int SetSlot_007f98b0(void* p, int index)
{
    if (index < 0 || index >= 0x20)
        return -1;
    g_slots_007f98b0[index] = p;
    return 0;
}
