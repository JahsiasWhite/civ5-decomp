// src: GUESS (confidence: low)
struct Slot16_0052e6d0
{
    int m_a;
    int m_b;
    int m_c;
    int m_d;
};

// src: GUESS (confidence: low)
struct Unk_0052e6d0
{
    int m_f00;
    int m_pad04;
    int m_f08;
    int m_pad0c;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1c;
    Slot16_0052e6d0 m_slots[32];

    // src: GUESS (confidence: high) [0x0052e6d0]
    Unk_0052e6d0();
};

Unk_0052e6d0::Unk_0052e6d0()
    : m_f00(0)
    , m_f08(0)
    , m_f10(0)
    , m_f14(0x800000)
    , m_f18(0x10000)
    , m_f1c(0x800)
{
    Slot16_0052e6d0* p = m_slots;
    for (int i = 31; i >= 0; --i)
    {
        p->m_a = 0;
        p->m_b = 0;
        p->m_c = 0;
        ++p;
    }
}
