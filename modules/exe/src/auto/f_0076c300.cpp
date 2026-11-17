// Returns bit 6 of the flag word at offset 0x44.

// src: GUESS (confidence: low)
class FlagBits_0076c300
{
public:
    // src: GUESS (confidence: low) [0x0076c300]
    bool GetFlag6() const;

    char m_pad[0x44];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

bool FlagBits_0076c300::GetFlag6() const
{
    return (m_flags >> 6) & 1;
}
