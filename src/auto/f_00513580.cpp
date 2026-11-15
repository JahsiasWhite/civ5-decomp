// c5d-model: claude-opus-5-5
// Counts how many of eight pointer slots are non-null.

struct EightSlotSet
{
    void* slots[8];

    int CountUsed() const;
};

int EightSlotSet::CountUsed() const
{
    int n = 0;
    if (slots[0] != 0) n = 1;
    if (slots[1] != 0) ++n;
    if (slots[2] != 0) ++n;
    if (slots[3] != 0) ++n;
    if (slots[4] != 0) ++n;
    if (slots[5] != 0) ++n;
    if (slots[6] != 0) ++n;
    if (slots[7] != 0) ++n;
    return n;
}
