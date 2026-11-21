// src: GUESS (confidence: low)
struct UnkBitset256_005c3c90
{
    unsigned char m_bits[0x20];

    bool TestBit_005c3c90(unsigned int idx);
};

// src: GUESS (confidence: medium) [0x005c3c90]
bool UnkBitset256_005c3c90::TestBit_005c3c90(unsigned int idx)
{
    unsigned int byteIdx = idx >> 3;
    if (byteIdx < 0x20)
        return (m_bits[byteIdx] & (1 << (idx & 7))) ? true : false;
    return false;
}
