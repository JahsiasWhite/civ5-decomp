// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low) [0x02c72cdc]
struct UnkGlobal_007f99a0
{
    char m_pad00[0x28];  // +0x00
    int m_f28;           // +0x28
    int m_f2c;           // +0x2c
};

// src: GUESS (confidence: low) [0x02c72cdc]
extern UnkGlobal_007f99a0* g_pUnk_007f99a0;

// src: GUESS (confidence: high) [0x007f99a0]
void GetGlobalPair_007f99a0(int* out1, int* out2)
{
    *out1 = g_pUnk_007f99a0->m_f2c;
    *out2 = g_pUnk_007f99a0->m_f28;
}
