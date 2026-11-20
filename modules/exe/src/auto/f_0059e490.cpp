// src: GUESS (confidence: low) [0x0059e490]
struct Unk_0059e490
{
    char m_pad00[0xa4];  // +0x00
    float m_fa4;         // +0xa4
    float m_fa8;         // +0xa8

    // src: GUESS (confidence: high) [0x0059e490]
    void SetScaled_0059e490(float x);
};

// src: GUESS (confidence: high) [0x0059e490]
void Unk_0059e490::SetScaled_0059e490(float x)
{
    if (0.0f > x)
        m_fa4 = 0.0f;
    else
        m_fa4 = m_fa8 * x;
}
