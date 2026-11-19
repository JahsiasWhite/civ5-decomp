// src: GUESS (confidence: low) [0x0606bb3c]
int g_slotLimit_0606bb3c;

// Slots run 0-15, further capped by the limit when one is set.
// src: GUESS (confidence: low) [0x009194f0]
int IsValidSlot_009194f0(unsigned int slot)
{
    if (slot < 16 && (!g_slotLimit_0606bb3c || (int)slot < g_slotLimit_0606bb3c))
        return 1;
    return 0;
}
