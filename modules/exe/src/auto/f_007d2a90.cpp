// Stores the given value in the field at offset 0x0d.

// src: GUESS (confidence: low)
class FieldOwner_005341d0
{
public:
    // src: GUESS (confidence: low) [0x005341d0]
    void SetField0d(bool value);

    char m_pad[0xd];
    // src: GUESS (confidence: low)
    bool m_field0d;
};

void FieldOwner_005341d0::SetField0d(bool value)
{
    m_field0d = value;
}
