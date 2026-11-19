// c5d-cflags: +/Od
// Replaces the low byte of the packed word at offset 0xe8.

// src: GUESS (confidence: low)
struct Packed_00897730
{
    char m_pad0[0xe8];
    // src: GUESS (confidence: low)
    unsigned int m_packed;
};

// src: GUESS (confidence: low) [0x00897730]
void SetPackedLow(Packed_00897730* p, unsigned int value)
{
    p->m_packed = (p->m_packed & 0xFFFFFF00) | (value & 0xFF);
}
