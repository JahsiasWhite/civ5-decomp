// src: GUESS (confidence: low) [0x006944c0]
struct Unk_006944c0
{
    int m_a;  // +0x00
    int m_b;  // +0x04

    // src: GUESS (confidence: low)
    bool IsEmpty() const { return m_a == 0 && m_b == 0; }

    // src: GUESS (confidence: high) [0x006944c0]
    int GetVal_006944c0();
};

// src: GUESS (confidence: high) [0x006944c0]
int Unk_006944c0::GetVal_006944c0()
{
    return IsEmpty() ? -1 : 4;
}
