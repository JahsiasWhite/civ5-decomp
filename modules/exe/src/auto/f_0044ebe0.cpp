// Sets the high bit of a flag byte near the end of a very large object.

// src: GUESS (confidence: low)
class LargeFlagOwner_0044ebe0
{
public:
    // src: GUESS (confidence: low) [0x0044ebe0]
    void SetHighFlag();

    char m_pad[0xc1504];
    // src: GUESS (confidence: low)
    unsigned char m_flags;
};

void LargeFlagOwner_0044ebe0::SetHighFlag()
{
    m_flags |= 0x80;
}
