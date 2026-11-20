// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low)
struct Inner_007f99d0
{
    int m_pad00[2];  // +0x00
    int m_id08;      // +0x08
};

// src: GUESS (confidence: low) [0x007f99d0]
struct Unk_007f99d0
{
    char m_pad00[0x8c];      // +0x00
    Inner_007f99d0* m_p8c;   // +0x8c
};

// src: GUESS (confidence: high) [0x007f99d0]
int GetId_007f99d0(Unk_007f99d0* p)
{
    if (p->m_p8c != 0)
        return p->m_p8c->m_id08;
    return -1;
}
