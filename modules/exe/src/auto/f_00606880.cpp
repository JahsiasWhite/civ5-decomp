// c5d-cflags: -/arch:IA32
// src: GUESS (confidence: low)
struct Unk20_00606880
{
    int m_d[5];
};

// src: GUESS (confidence: high) [0x00606880]
Unk20_00606880* CopyRange_00606880(const Unk20_00606880* first, const Unk20_00606880* last, Unk20_00606880* dst)
{
    while (first != last)
    {
        dst->m_d[0] = first->m_d[0];
        dst->m_d[1] = first->m_d[1];
        dst->m_d[2] = first->m_d[2];
        dst->m_d[3] = first->m_d[3];
        dst->m_d[4] = first->m_d[4];
        ++first;
        ++dst;
    }
    return dst;
}
