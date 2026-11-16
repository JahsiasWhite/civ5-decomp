// Stores the given value in the field at offset 0x54.

// src: GUESS (confidence: low)
class FieldOwner_00406270
{
public:
    // src: GUESS (confidence: low) [0x00406270]
    void SetField54(int value);

    char m_pad[0x54];
    // src: GUESS (confidence: low)
    int m_field54;
};

void FieldOwner_00406270::SetField54(int value)
{
    m_field54 = value;
}
