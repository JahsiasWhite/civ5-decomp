// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: low) [0x008091d0]
struct Unk_008091d0
{
    char m_pad00[0x104];  // +0x00
    int m_offset104;      // +0x104
};

// src: GUESS (confidence: high) [0x008091d0]
void* GetEnd_008091d0(Unk_008091d0* p)
{
    Unk_008091d0* q = p;
    void* res = (char*)q + q->m_offset104;
    return res;
}
