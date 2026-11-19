// Hands out `count` 16-bit slots from the pool: reports the start index
// and its address, then advances the pool.

// src: GUESS (confidence: low)
class ShortPool_00799fc0
{
public:
    // src: GUESS (confidence: low) [0x00799fc0]
    void Allocate(int count, short** outSlots, int* outIndex);

    char m_pad0[0x2434];
    // src: GUESS (confidence: low)
    int m_used;
    char m_pad2438[0x2448 - 0x2438];
    // src: GUESS (confidence: low)
    short* m_slots;
};

void ShortPool_00799fc0::Allocate(int count, short** outSlots, int* outIndex)
{
    *outIndex = m_used;
    *outSlots = m_slots + m_used;
    m_used += count;
}
