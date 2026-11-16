// Returns whether the field at offset 0x20 is set (non-zero).

// src: GUESS (confidence: low)
class FieldOwner_0090e840
{
public:
    // src: GUESS (confidence: low) [0x0090e840]
    bool HasField20() const;

    char m_pad[0x20];
    // src: GUESS (confidence: low)
    int m_field20;
};

bool FieldOwner_0090e840::HasField20() const
{
    return m_field20 != 0;
}
