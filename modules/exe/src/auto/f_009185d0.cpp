// Returns bit 2 of the flag byte at offset 0x30.

// src: GUESS (confidence: low)
class FlagBits_009185d0
{
public:
    // src: GUESS (confidence: low) [0x009185d0]
    bool GetFlag2() const;

    char m_pad[0x30];
    // src: GUESS (confidence: low)
    unsigned char m_flag0 : 1;
    // src: GUESS (confidence: low)
    unsigned char m_flag1 : 1;
    // src: GUESS (confidence: low)
    unsigned char m_flag2 : 1;
};

bool FlagBits_009185d0::GetFlag2() const
{
    return m_flag2;
}
