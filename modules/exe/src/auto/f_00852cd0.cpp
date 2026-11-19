// Returns field 8 of the object in slot `index`, or 0 when the index is out of
// range or the slot is empty.

#include <vector>

// src: GUESS (confidence: low)
struct Item_008ed240
{
    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low)
struct Slot_008ed240
{
    // src: GUESS (confidence: low)
    Item_008ed240* m_item;
    int m_04;
};

// src: GUESS (confidence: low)
class SlotTable_008ed240
{
public:
    // src: GUESS (confidence: low) [0x008ed240]
    int GetSlotValue(unsigned int index) const;

    char m_pad0[0x30];
    // src: GUESS (confidence: low)
    std::vector<Slot_008ed240> m_slots;
};

int SlotTable_008ed240::GetSlotValue(unsigned int index) const
{
    if (index < m_slots.size())
    {
        const Slot_008ed240& slot = m_slots[index];
        if (slot.m_item)
            return slot.m_item->m_value;
    }
    return 0;
}
