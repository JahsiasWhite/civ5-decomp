// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low) [0x02c72d18]
extern void (__cdecl* g_fn_0080b300)(int, int);

// src: GUESS (confidence: low)
struct Inner_0080b300
{
    char m_pad00[0x14];  // +0x00
    int m_f14;           // +0x14
};

// src: GUESS (confidence: low) [0x0080b300]
struct Unk_0080b300
{
    char m_pad00[0x1c];    // +0x00
    Inner_0080b300* m_p1c; // +0x1c
};

// src: GUESS (confidence: high) [0x0080b300]
void CallFn_0080b300(Unk_0080b300* p)
{
    Inner_0080b300* q = p->m_p1c;
    (*g_fn_0080b300)(q->m_f14, -1);
}
