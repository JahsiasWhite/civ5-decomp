// src: GUESS (confidence: low) [0x00835e70]
struct Unk_00835e70
{
    char m_pad00[0x18];       // +0x00
    unsigned int m_cur;       // +0x18
    unsigned int m_prev;      // +0x1c
    unsigned short m_step;    // +0x20
};

// src: GUESS (confidence: high) [0x00835e70]
unsigned int __stdcall Advance_00835e70(Unk_00835e70* s, unsigned int step)
{
    s->m_prev = s->m_cur;
    s->m_cur = s->m_cur + (unsigned short)step;
    s->m_step = (unsigned short)step;
    return s->m_prev;
}
