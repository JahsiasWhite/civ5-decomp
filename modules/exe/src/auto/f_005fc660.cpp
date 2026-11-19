// Returns a slot to a pool's free list, which is kept sorted by index.

// src: GUESS (confidence: low)
struct PoolSlot_006e3a50
{
    // src: GUESS (confidence: low)
    bool m_free;
    // src: GUESS (confidence: low)
    unsigned int m_nextFree;
    char m_pad8[0x20 - 8];
};

// src: GUESS (confidence: low)
struct SlotPool_006e3a50
{
    // src: GUESS (confidence: low) [0x006e3a50]
    void Release(unsigned int index);

    char m_pad0[0x14];
    // src: GUESS (confidence: low)
    unsigned int m_firstFree;
    // src: GUESS (confidence: low)
    int m_used;
    // src: GUESS (confidence: low)
    PoolSlot_006e3a50* m_slots;
};

void SlotPool_006e3a50::Release(unsigned int index)
{
    PoolSlot_006e3a50& slot = m_slots[index];
    slot.m_free = true;
    if (index < m_firstFree)
    {
        slot.m_nextFree = m_firstFree;
        --m_used;
        m_firstFree = index;
    }
    else
    {
        PoolSlot_006e3a50& head = m_slots[m_firstFree];
        slot.m_nextFree = head.m_nextFree;
        head.m_nextFree = index;
        --m_used;
    }
}
