// c5d-cflags: -/arch:IA32
// src: GUESS (confidence: low)
struct Unk16_0069c850
{
    int m_a;
    int m_b;
    int m_c;
    int m_d;
};

// src: GUESS (confidence: high) [0x0069c850]
Unk16_0069c850* CopyRange_0069c850(const Unk16_0069c850* first, const Unk16_0069c850* last, Unk16_0069c850* dst)
{
    while (first != last)
    {
        if (dst)
        {
            dst->m_a = first->m_a;
            dst->m_b = first->m_b;
            dst->m_c = first->m_c;
            dst->m_d = first->m_d;
        }
        ++first;
        ++dst;
    }
    return dst;
}
