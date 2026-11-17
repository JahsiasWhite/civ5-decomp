// c5d-model: Gemini 4 Hydrogen
// Returns the byte field at offset 0x149.

// src: GUESS (confidence: medium)
class ByteGetter_006e1fc0
{
public:
    // src: GUESS (confidence: medium) [0x006e1fc0]
    char GetByte() const;

    // src: GUESS (confidence: high)
    char pad0[0x149];
    // src: GUESS (confidence: medium)
    char m_value;
};

char ByteGetter_006e1fc0::GetByte() const
{
    return m_value;
}
