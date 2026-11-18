// src: GUESS (confidence: low) [0x0064b820]
class UnkFlags_0064b820
{
public:
    // src: GUESS (confidence: low) [0x0064b820]
    void SetFlag08000000(bool bOn);

    char m_pad0[0x40];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

void UnkFlags_0064b820::SetFlag08000000(bool bOn)
{
    unsigned int uFlags = m_flags;
    if (bOn)
        m_flags = uFlags | 0x08000000;
    else
        m_flags = uFlags & ~0x08000000;
}
