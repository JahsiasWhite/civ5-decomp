// Stores the given value in the field at offset 0x3c.

// src: GUESS (confidence: low)
class FieldOwner_00463a00
{
public:
    // src: GUESS (confidence: low) [0x00463a00]
    void SetField3c(int value);

    char m_pad[0x3c];
    // src: GUESS (confidence: low)
    int m_field3c;
};

void FieldOwner_00463a00::SetField3c(int value)
{
    m_field3c = value;
}
