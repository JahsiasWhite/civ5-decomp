// Clears the field at offset 0x68.

// src: GUESS (confidence: low)
class FieldOwner_00761040
{
public:
    // src: GUESS (confidence: low) [0x00761040]
    void ClearField68();

    char m_pad[0x68];
    // src: GUESS (confidence: low)
    int m_field68;
};

void FieldOwner_00761040::ClearField68()
{
    m_field68 = 0;
}
