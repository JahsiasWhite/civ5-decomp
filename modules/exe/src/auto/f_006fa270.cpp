// Stores the given value in the field at offset 0x50.

// src: GUESS (confidence: low)
class FieldOwner_006fa270
{
public:
    // src: GUESS (confidence: low) [0x006fa270]
    void SetField50(int value);

    char m_pad[0x50];
    // src: GUESS (confidence: low)
    int m_field50;
};

void FieldOwner_006fa270::SetField50(int value)
{
    m_field50 = value;
}
