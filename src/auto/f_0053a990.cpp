// Stores the given value in the field at offset 0x38.
// Seven classes share this body in their vtables (identical virtual setters
// folded by the linker).

// src: GUESS (confidence: low)
class FieldOwner_0053a990
{
public:
    // src: GUESS (confidence: low) [0x0053a990]
    void SetField38(int value);

    char m_pad[0x38];
    // src: GUESS (confidence: low)
    int m_field38;
};

void FieldOwner_0053a990::SetField38(int value)
{
    m_field38 = value;
}
