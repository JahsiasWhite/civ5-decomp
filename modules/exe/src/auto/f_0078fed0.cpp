// src: GUESS (confidence: low)
struct Elem8_0078fed0
{
    int m_a;  // +0x00
    int m_b;  // +0x04
};

// src: GUESS (confidence: low) [0x0078fed0]
struct Unk_0078fed0
{
    int m_pad00;             // +0x00
    Elem8_0078fed0* m_begin; // +0x04
    Elem8_0078fed0* m_end;   // +0x08

    // src: GUESS (confidence: high) [0x0078fed0]
    bool Contains_0078fed0(int val);
};

// src: GUESS (confidence: high) [0x0078fed0]
bool Unk_0078fed0::Contains_0078fed0(int val)
{
    for (Elem8_0078fed0* it = m_begin; it != m_end; ++it)
    {
        if (it->m_b == val)
            return true;
    }
    return false;
}
