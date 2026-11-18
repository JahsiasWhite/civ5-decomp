// Hands out `count` 48-byte slots from the pool: reports the start index and
// its address, then advances the pool.

// src: GUESS (confidence: low)
struct Slot_00452a90
{
    int m_data[12];
};

// src: GUESS (confidence: low)
class SlotPool_00452a90
{
public:
    // src: GUESS (confidence: low) [0x00452a90]
    void Allocate(int count, Slot_00452a90** outSlots, int* outIndex);

    char m_pad0[0x243c];
    // src: GUESS (confidence: low)
    int m_used;
    // src: GUESS (confidence: low)
    Slot_00452a90* m_slots;
};

void SlotPool_00452a90::Allocate(int count, Slot_00452a90** outSlots, int* outIndex)
{
    *outIndex = m_used;
    *outSlots = m_slots + m_used;
    m_used += count;
}
