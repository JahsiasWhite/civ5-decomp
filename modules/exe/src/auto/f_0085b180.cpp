// src: GUESS (confidence: low) [0x0085b180]
struct Unk_0085b180
{
    char m_pad00[0x28];   // +0x00
    unsigned int m_f28;   // +0x28
    char m_pad2c[0x144];  // +0x2c
    unsigned int m_f170;  // +0x170

    // src: GUESS (confidence: high) [0x0085b180]
    bool Check_0085b180(unsigned int n);
};

// src: GUESS (confidence: high) [0x0085b180]
bool Unk_0085b180::Check_0085b180(unsigned int n)
{
    if (n > 0)
    {
        unsigned int end = m_f170 + n;
        if (end > m_f28 || end <= m_f170)
            return false;
    }
    return true;
}
