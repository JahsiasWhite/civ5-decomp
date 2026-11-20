// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low)
struct Inner_0080e680
{
    char m_pad00[0x50];  // +0x00
    int m_f50;           // +0x50
    int m_f54;           // +0x54
};

// src: GUESS (confidence: low) [0x0080e680]
struct Unk_0080e680
{
    char m_pad00[0x318];    // +0x00
    Inner_0080e680* m_p318; // +0x318
};

// src: GUESS (confidence: high) [0x0080e680]
void Set50_54_0080e680(Unk_0080e680* p, int a, int b)
{
    p->m_p318->m_f50 = a;
    p->m_p318->m_f54 = b;
}
