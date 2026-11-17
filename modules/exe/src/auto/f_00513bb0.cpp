// c5d-model: Gemini 4 Hydrogen
// Bitwise-inverts the 32-bit field at offset 0.

// src: GUESS (confidence: medium)
class BitwiseNot_00513bb0
{
public:
    // src: GUESS (confidence: medium) [0x00513bb0]
    void Invert();

    // src: GUESS (confidence: medium)
    unsigned int m_value;
};

void BitwiseNot_00513bb0::Invert()
{
    m_value = ~m_value;
}
