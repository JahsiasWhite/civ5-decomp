// Returns whether the field at offset 0x68 is set (non-zero).

// src: GUESS (confidence: low)
class FieldOwner_006843a0
{
public:
    // src: GUESS (confidence: low) [0x006843a0]
    bool HasField68() const;

    char m_pad[0x68];
    // src: GUESS (confidence: low)
    int m_field68;
};

bool FieldOwner_006843a0::HasField68() const
{
    return m_field68 != 0;
}
