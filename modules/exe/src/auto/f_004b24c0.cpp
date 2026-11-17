// Stores the given value in the field at offset 0x2c. Seven classes share this
// body in their vtables (identical virtual setters folded by the linker).

// src: GUESS (confidence: low)
class FieldOwner_004b24c0
{
public:
    // src: GUESS (confidence: low) [0x004b24c0]
    void SetField2c(int value);

    char m_pad[0x2c];
    // src: GUESS (confidence: low)
    int m_field2c;
};

void FieldOwner_004b24c0::SetField2c(int value)
{
    m_field2c = value;
}
