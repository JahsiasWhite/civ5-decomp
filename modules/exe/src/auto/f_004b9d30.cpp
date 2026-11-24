// src: GUESS (confidence: low)
struct S1_004b9d30
{
    float m_f[36];

    // src: GUESS (confidence: low)
    __forceinline S1_004b9d30()
    {
        m_f[0] = 0.0f;  m_f[1] = 0.0f;  m_f[2] = 0.0f;  m_f[3] = 0.0f;
        m_f[4] = 0.0f;  m_f[5] = 0.0f;  m_f[6] = 0.0f;  m_f[7] = 0.0f;
        m_f[8] = 0.0f;  m_f[9] = 0.0f;  m_f[10] = 0.0f; m_f[11] = 0.0f;
        m_f[12] = 0.0f; m_f[13] = 0.0f; m_f[14] = 0.0f; m_f[15] = 0.0f;
        m_f[16] = 0.0f; m_f[17] = 0.0f; m_f[18] = 0.0f; m_f[19] = 0.0f;
        m_f[20] = 0.0f; m_f[21] = 0.0f; m_f[22] = 0.0f; m_f[23] = 0.0f;
        m_f[24] = 0.0f; m_f[25] = 0.0f; m_f[26] = 0.0f; m_f[27] = 0.0f;
        m_f[28] = 0.0f; m_f[29] = 0.0f; m_f[30] = 0.0f; m_f[31] = 0.0f;
        m_f[32] = 0.0f; m_f[33] = 0.0f; m_f[34] = 0.0f; m_f[35] = 0.0f;
    }
};

// src: GUESS (confidence: low)
struct Pair_004b9d30
{
    int a;
    int b;
};

// src: GUESS (confidence: low)
struct S2_004b9d30
{
    float m_f[12];
    Pair_004b9d30 m_p[16];

    // src: GUESS (confidence: low)
    __forceinline S2_004b9d30()
    {
        m_f[0] = 0.0f; m_f[1] = 0.0f; m_f[2] = 0.0f;  m_f[3] = 0.0f;
        m_f[4] = 0.0f; m_f[5] = 0.0f; m_f[6] = 0.0f;  m_f[7] = 0.0f;
        m_f[8] = 0.0f; m_f[9] = 0.0f; m_f[10] = 0.0f; m_f[11] = 0.0f;
        m_p[0].b = 0;  m_p[0].a = 0;  m_p[1].b = 0;  m_p[1].a = 0;
        m_p[2].b = 0;  m_p[2].a = 0;  m_p[3].b = 0;  m_p[3].a = 0;
        m_p[4].b = 0;  m_p[4].a = 0;  m_p[5].b = 0;  m_p[5].a = 0;
        m_p[6].b = 0;  m_p[6].a = 0;  m_p[7].b = 0;  m_p[7].a = 0;
        m_p[8].b = 0;  m_p[8].a = 0;  m_p[9].b = 0;  m_p[9].a = 0;
        m_p[10].b = 0; m_p[10].a = 0; m_p[11].b = 0; m_p[11].a = 0;
        m_p[12].b = 0; m_p[12].a = 0; m_p[13].b = 0; m_p[13].a = 0;
        m_p[14].b = 0; m_p[14].a = 0; m_p[15].b = 0; m_p[15].a = 0;
    }
};

// src: GUESS (confidence: low) [0x004b9d30]
class Der_004b9d30
{
public:
    // src: GUESS (confidence: low) [0x004b9d30]
    Der_004b9d30();

private:
    unsigned char m_pad00[0x6d0];
    S1_004b9d30 m_s1;
    S2_004b9d30 m_s2;
};

Der_004b9d30::Der_004b9d30()
{
}
