// src: GUESS (confidence: low)
struct UnkItem80_00560750
{
    int m_pad[19];
    float m_val4c;
};

// src: GUESS (confidence: low)
struct UnkContainer_00560750
{
    char m_pad[0x40c2c];
    UnkItem80_00560750* m_items;
    unsigned int m_count;

    float GetItemFloat_00560750(unsigned int idx);
};

// src: GUESS (confidence: medium) [0x00560750]
float UnkContainer_00560750::GetItemFloat_00560750(unsigned int idx)
{
    if (idx >= m_count)
        return 0.0f;
    return m_items[idx].m_val4c;
}
