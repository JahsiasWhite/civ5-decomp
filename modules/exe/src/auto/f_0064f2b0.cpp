// src: GUESS (confidence: low)
struct Pod64_0064f2b0
{
    int m_data[16];
};

// src: GUESS (confidence: low)
struct Arg_0064f2b0
{
    Pod64_0064f2b0 m_p00;  // +0x00
    unsigned char m_f40;   // +0x40
};

// src: GUESS (confidence: low) [0x0064f2b0]
struct Unk_0064f2b0
{
    int m_pad00[2];        // +0x00
    Pod64_0064f2b0 m_p08;  // +0x08
    char m_pad48[0x5c];    // +0x48
    unsigned char m_fa4;   // +0xa4

    // src: GUESS (confidence: high) [0x0064f2b0]
    void Copy_0064f2b0(const Arg_0064f2b0& arg);
};

// src: GUESS (confidence: high) [0x0064f2b0]
void Unk_0064f2b0::Copy_0064f2b0(const Arg_0064f2b0& arg)
{
    m_p08 = arg.m_p00;
    m_fa4 = arg.m_f40;
}
