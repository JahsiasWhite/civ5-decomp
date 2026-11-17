// Stores the given value in the field at offset 0x0c.

// src: GUESS (confidence: low)
class FieldOwner_00617f20
{
public:
    // src: GUESS (confidence: low) [0x00617f20]
    void SetField0c(bool value);

    char m_pad[0xc];
    // src: GUESS (confidence: low)
    bool m_field0c;
};

void FieldOwner_00617f20::SetField0c(bool value)
{
    m_field0c = value;
}
