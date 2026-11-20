// src: GUESS (confidence: low)
struct Elem8_0078fd90
{
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low) [0x0078fd90]
struct Unk_0078fd90
{
    int m_pad00;             // +0x00
    Elem8_0078fd90* m_begin; // +0x04
    Elem8_0078fd90* m_end;   // +0x08
    int m_pad0c;             // +0x0c
    unsigned int m_idx;      // +0x10

    // src: GUESS (confidence: high) [0x0078fd90]
    bool Advance_0078fd90();
};

// src: GUESS (confidence: high) [0x0078fd90]
bool Unk_0078fd90::Advance_0078fd90()
{
    unsigned int count = (unsigned int)(m_end - m_begin);
    if (count != 0)
    {
        m_idx = (m_idx + 1) % count;
        return m_idx == 0;
    }
    return false;
}
