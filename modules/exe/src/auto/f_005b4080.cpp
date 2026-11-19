// Clears the one-byte flag at offset 0x2b1a0 of a large object.

// src: GUESS (confidence: low)
class FlagOwner_007049f0
{
public:
    // src: GUESS (confidence: low) [0x007049f0]
    void ClearFlag2b1a0();

    char m_pad[0x2b1a0];
    // src: GUESS (confidence: low)
    bool m_flag2b1a0;
};

void FlagOwner_007049f0::ClearFlag2b1a0()
{
    m_flag2b1a0 = false;
}
