// Totals the counts of the 16 slots.

// src: GUESS (confidence: low)
struct Slot_0091e7e0
{
    // src: GUESS (confidence: low)
    int m_count;
    int m_04;
};

// src: GUESS (confidence: low)
class SlotSet_0091e7e0
{
public:
    // src: GUESS (confidence: low) [0x0091e7e0]
    int GetTotal() const;

    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    Slot_0091e7e0 m_slots[16];
};

int SlotSet_0091e7e0::GetTotal() const
{
    int total = 0;
    for (int i = 0; i < 16; ++i)
        total += m_slots[i].m_count;
    return total;
}
