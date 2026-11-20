// c5d-cflags: +/Oy-
// src: GUESS (confidence: low)
struct Inner_0041bda0
{
    int m_f00;                                      // +0x00
    void (__cdecl* m_fn)(Inner_0041bda0*, int, int);// +0x04
};

// c5d-cflags: +/Oy-
// src: GUESS (confidence: low) [0x0041bda0]
struct Unk_0041bda0
{
    char m_pad00[0x10];     // +0x00
    Inner_0041bda0* m_p10;  // +0x10
    int m_f14;              // +0x14
    int m_f18;              // +0x18
};

// src: GUESS (confidence: high) [0x0041bda0]
void Dispatch_0041bda0(Unk_0041bda0* p, int a, int b)
{
    p->m_f18 = 0;
    p->m_f14 = 0;
    p->m_p10->m_fn(p->m_p10, a, b);
}
