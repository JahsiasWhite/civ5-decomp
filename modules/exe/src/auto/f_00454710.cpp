// Stores the given value in the field at offset 0x58.

// src: GUESS (confidence: low)
class FieldOwner_00454710
{
public:
    // src: GUESS (confidence: low) [0x00454710]
    void SetField58(int value);

    char m_pad[0x58];
    // src: GUESS (confidence: low)
    int m_field58;
};

void FieldOwner_00454710::SetField58(int value)
{
    m_field58 = value;
}
