// src: GUESS (confidence: low)
struct UnkItem28_0060eb30
{
    int m_pad00[5];
    unsigned int m_val14;
    int m_pad18;
};

// src: GUESS (confidence: low)
struct UnkContainer_0060eb30
{
    int m_pad00[2];
    UnkItem28_0060eb30* m_items;
    unsigned int m_count;

    int IsNonNegative_0060eb30(unsigned int idx);
};

// src: GUESS (confidence: medium) [0x0060eb30]
int UnkContainer_0060eb30::IsNonNegative_0060eb30(unsigned int idx)
{
    if (idx < m_count && !((unsigned char)(m_items[idx].m_val14 >> 31) & 1))
        return 1;
    return 0;
}
