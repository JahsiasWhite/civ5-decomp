// c5d-cflags: +/Od
// Sets slot `index` (of 8) of the object; -1 when out of range.

// src: GUESS (confidence: low)
struct Slot_00895780
{
    int m_data[8];
};

// src: GUESS (confidence: low)
struct Object_00895780
{
    char m_pad0[0x16c];
    // src: GUESS (confidence: low)
    Slot_00895780 m_slots[8];
};

// src: GUESS (confidence: low) [0x00895780]
int SetSlot_00895780(Object_00895780* object, int index, const Slot_00895780* slot)
{
    if (index >= 0 && index < 8)
    {
        object->m_slots[index] = *slot;
        return 0;
    }
    return -1;
}
