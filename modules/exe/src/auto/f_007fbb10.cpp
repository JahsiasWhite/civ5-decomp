// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low)
struct Inner_007fbb10
{
    char m_pad00[0x124];  // +0x00
    int m_f124;           // +0x124
    int m_f128;           // +0x128
    int m_f12c;           // +0x12c
};

// src: GUESS (confidence: low) [0x007fbb10]
struct Unk_007fbb10
{
    char m_pad00[0x104];   // +0x00
    Inner_007fbb10* m_p104;// +0x104
};

// src: GUESS (confidence: high) [0x007fbb10]
void Copy124To12c_007fbb10(Unk_007fbb10* p)
{
    p->m_p104->m_f12c = p->m_p104->m_f124;
}
