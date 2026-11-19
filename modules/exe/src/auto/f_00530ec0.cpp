// Hands out `count` 24-byte slots from the pool: reports the start index and
// its address, then advances the pool.

// src: GUESS (confidence: low)
struct Slot_00691750
{
    int m_data[6];
};

// src: GUESS (confidence: low)
class SlotPool_00691750
{
public:
    // src: GUESS (confidence: low) [0x00691750]
    void Allocate(int count, Slot_00691750** outSlots, int* outIndex);

    char m_pad0[0x2438];
    // src: GUESS (confidence: low)
    int m_used;
    char m_pad243c[0x2444 - 0x243c];
    // src: GUESS (confidence: low)
    Slot_00691750* m_slots;
};

void SlotPool_00691750::Allocate(int count, Slot_00691750** outSlots, int* outIndex)
{
    *outIndex = m_used;
    *outSlots = m_slots + m_used;
    m_used += count;
}
