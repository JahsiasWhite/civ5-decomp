// src: GUESS (confidence: low) [0x00688820]
struct Unk_00688820
{
    char m_pad00[0x134];  // +0x00
    int m_f134;           // +0x134
    int m_f138;           // +0x138
    int m_f13c;           // +0x13c

    // src: GUESS (confidence: high) [0x00688820]
    int Advance_00688820(int n);
};

// src: GUESS (confidence: high) [0x00688820]
int Unk_00688820::Advance_00688820(int n)
{
    int prev = m_f134 + m_f138;
    m_f13c = n;
    m_f138 += n;
    return prev;
}
