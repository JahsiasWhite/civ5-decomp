// Returns whether the field at offset 0x7c is set (non-zero).

// src: GUESS (confidence: low)
class FieldOwner_007bebc0
{
public:
    // src: GUESS (confidence: low) [0x007bebc0]
    bool HasField7c() const;

    char m_pad[0x7c];
    // src: GUESS (confidence: low)
    int m_field7c;
};

bool FieldOwner_007bebc0::HasField7c() const
{
    return m_field7c != 0;
}
