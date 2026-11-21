// src: GUESS (confidence: low)
struct UnkItem3224_0065ac40
{
    int m_pad00;
    unsigned int m_val04;
    char m_pad08[0xc90];
};

// src: GUESS (confidence: low)
struct UnkContainer_0065ac40
{
    int m_pad00[3];
    UnkItem3224_0065ac40* m_items;
    unsigned int m_count;

    int IsNonNegative_0065ac40(unsigned int idx);
};

// src: GUESS (confidence: medium) [0x0065ac40]
int UnkContainer_0065ac40::IsNonNegative_0065ac40(unsigned int idx)
{
    if (idx < m_count)
    {
        unsigned char b = (unsigned char)(m_items[idx].m_val04 >> 31);
        b = ~b;
        if (!(b & 1))
            return 1;
    }
    return 0;
}
