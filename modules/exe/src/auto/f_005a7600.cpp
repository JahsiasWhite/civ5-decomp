// src: GUESS (confidence: low)
struct UnkItem12_005a7600
{
    int m_f00;
    int m_f04;
    int m_f08;
};

// src: GUESS (confidence: low)
struct UnkTarget_005a7600
{
    int m_pad[3];
    int m_f0c;
    int m_f10;
};

// src: GUESS (confidence: low)
struct UnkOwner_005a7600
{
    int m_pad00[3];
    UnkItem12_005a7600* m_items;
    char m_pad10[0x48];
    UnkTarget_005a7600* m_target;
};

// src: GUESS (confidence: medium) [0x005a7600]
bool __stdcall TryMerge_005a7600(UnkOwner_005a7600* owner, int idx)
{
    if (owner->m_target)
    {
        if (owner->m_target->m_f0c * 3 + owner->m_target->m_f10 == owner->m_items[idx].m_f04 * 3)
        {
            owner->m_target->m_f0c += owner->m_items[idx].m_f08;
            return true;
        }
    }
    return false;
}
