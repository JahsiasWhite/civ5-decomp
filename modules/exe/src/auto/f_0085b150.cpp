// src: GUESS (confidence: low) [0x0085b150]
struct Unk_0085b150
{
    char m_pad00[0x2c];   // +0x00
    unsigned int m_f2c;   // +0x2c
    char m_pad30[0x120];  // +0x30
    unsigned int m_f150;  // +0x150

    // src: GUESS (confidence: high) [0x0085b150]
    bool Check_0085b150(unsigned int n);
};

// src: GUESS (confidence: high) [0x0085b150]
bool Unk_0085b150::Check_0085b150(unsigned int n)
{
    if (n > 0)
    {
        unsigned int end = m_f150 + n;
        if (end > m_f2c || end <= m_f150)
            return false;
    }
    return true;
}
