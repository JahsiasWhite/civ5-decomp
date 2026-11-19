// src: GUESS (confidence: low)
struct Unk_00634190
{
    unsigned char m_flags;
    char m_pad01[0xc7b];
    int m_type;

    // src: GUESS (confidence: high) [0x00634190]
    void SetType(int t);
};

void Unk_00634190::SetType(int t)
{
    m_flags &= 0xc3;
    m_type = t;
    switch (t)
    {
    case 2:
        m_flags |= 8;
        break;
    case 4:
        m_flags |= 0x10;
        break;
    case 8:
        m_flags |= 0x20;
        break;
    default:
        m_flags |= 4;
        break;
    }
}
