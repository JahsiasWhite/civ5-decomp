// c5d-model: Gemini 4 Hydrogen
// Returns the byte field at offset 0x148.

// src: GUESS (confidence: medium)
class ByteGetter_0046b1a0
{
public:
    // src: GUESS (confidence: medium) [0x0046b1a0]
    char GetByte() const;

    // src: GUESS (confidence: high)
    char pad0[0x148];
    // src: GUESS (confidence: medium)
    char m_value;
};

char ByteGetter_0046b1a0::GetByte() const
{
    return m_value;
}
