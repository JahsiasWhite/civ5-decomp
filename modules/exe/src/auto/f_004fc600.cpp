// src: GUESS (confidence: low) [0x004fc600]
struct Unk_004fc600
{
    float m_f00;          // +0x00
    float m_f04;          // +0x04
    int m_f08;            // +0x08
    int m_f0c;            // +0x0c
    unsigned char m_f10;  // +0x10

    // src: GUESS (confidence: high) [0x004fc600]
    Unk_004fc600();
};

// src: GUESS (confidence: high) [0x004fc600]
Unk_004fc600::Unk_004fc600()
    : m_f00(1.0f)
    , m_f04(1.0f)
    , m_f08(-1)
    , m_f0c(1)
    , m_f10(0)
{
}
