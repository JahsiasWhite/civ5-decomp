// c5d-cflags: +/Od
// Returns slot `index` (of 8) of the object; -1 when out of range.

// src: GUESS (confidence: low)
struct Slot_00895740
{
    int m_data[8];
};

// src: GUESS (confidence: low)
struct Object_00895740
{
    char m_pad0[0x16c];
    // src: GUESS (confidence: low)
    Slot_00895740 m_slots[8];
};

// src: GUESS (confidence: low) [0x00895740]
int GetSlot_00895740(Slot_00895740** out, Object_00895740* object, int index)
{
    *out = 0;
    if (index >= 0 && index < 8)
    {
        *out = &object->m_slots[index];
        return 0;
    }
    return -1;
}
