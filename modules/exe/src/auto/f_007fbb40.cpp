// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low)
struct Inner_007fbb40
{
    char m_pad00[0x12c];  // +0x00
    void** m_p12c;        // +0x12c
};

// src: GUESS (confidence: low) [0x007fbb40]
struct Unk_007fbb40
{
    char m_pad00[0x104];    // +0x00
    Inner_007fbb40* m_p104; // +0x104
};

// src: GUESS (confidence: high) [0x007fbb40]
void Pop12c_007fbb40(Unk_007fbb40* p)
{
    p->m_p104->m_p12c = (void**)*p->m_p104->m_p12c;
}
