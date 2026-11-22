// src: GUESS (confidence: low) [0x00472800]
class Class_00472800
{
public:
    unsigned char m_pad0[6];
    unsigned char m_flag;
    unsigned char m_pad1[5];
    unsigned int m_bits;

    void ClearBits(unsigned int mask);
};

void Class_00472800::ClearBits(unsigned int mask)
{
    m_bits &= ~mask;
    if (mask & 0x10)
        m_flag = 0;
}
