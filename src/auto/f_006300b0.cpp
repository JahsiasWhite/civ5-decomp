// Claims the first free slot among slots 1..3 (slot 0 is reserved): marks it
// used and returns its index, or -1 when all are taken.

// src: GUESS (confidence: low)
class SlotSet_006300b0
{
public:
    // src: GUESS (confidence: low) [0x006300b0]
    int ClaimSlot();

    // src: GUESS (confidence: low)
    bool m_used[4];
};

int SlotSet_006300b0::ClaimSlot()
{
    for (unsigned int i = 1; i < 4; ++i)
    {
        if (!m_used[i])
        {
            m_used[i] = true;
            return i;
        }
    }
    return -1;
}
