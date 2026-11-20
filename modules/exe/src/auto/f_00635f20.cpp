// src: EXE [0x00a1bc68]
extern float g_minPositive_00a0b4ec;

// src: GUESS (confidence: low)
struct UnkInner_00635f20
{
    float m_f00;
    float m_f04;
};

// src: GUESS (confidence: low)
struct UnkObj_00635f20
{
    char m_pad[0x5c];
    UnkInner_00635f20* m_p5c;

    float GetPositiveOrDefault_00635f20();
};

// src: GUESS (confidence: medium) [0x00635f20]
float UnkObj_00635f20::GetPositiveOrDefault_00635f20()
{
    float v = m_p5c->m_f04;
    if (v != g_minPositive_00a0b4ec)
        return v;
    return m_p5c->m_f00;
}
