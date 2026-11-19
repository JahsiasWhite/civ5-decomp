// c5d-cflags: -/arch:IA32
// src: GUESS (confidence: low)
struct Unk20_00648600
{
    int m_d[5];
};

// src: GUESS (confidence: high) [0x00648600]
Unk20_00648600* CopyBackward_00648600(const Unk20_00648600* first, const Unk20_00648600* last, Unk20_00648600* dst)
{
    while (first != last)
    {
        --dst;
        --last;
        dst->m_d[0] = last->m_d[0];
        dst->m_d[1] = last->m_d[1];
        dst->m_d[2] = last->m_d[2];
        dst->m_d[3] = last->m_d[3];
        dst->m_d[4] = last->m_d[4];
    }
    return dst;
}
