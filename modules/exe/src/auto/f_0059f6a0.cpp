// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct UnkBlock20_0059f6a0
{
    int data[5];
};

// src: GUESS (confidence: low)
struct UnkInner_0059f6a0
{
    char m_pad[0x1f4];
    UnkBlock20_0059f6a0 m_block;
};

// src: GUESS (confidence: low)
struct UnkOuter_0059f6a0
{
    int m_pad00[2];
    UnkInner_0059f6a0* m_inner;
    char m_pad0c[0x17dc0];
    UnkBlock20_0059f6a0 m_copy;

    UnkBlock20_0059f6a0* GetBlock_0059f6a0();
};

// src: GUESS (confidence: medium) [0x0059f6a0]
UnkBlock20_0059f6a0* UnkOuter_0059f6a0::GetBlock_0059f6a0()
{
    if (m_inner)
        m_copy = m_inner->m_block;
    return &m_copy;
}
