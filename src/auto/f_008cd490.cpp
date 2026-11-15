// c5d-model: claude-opus-5-5
// Clears a handful of counters/pointers on an object with a large inline
// buffer (the last field sits past an ~8KB block).

class ResetState8cd490
{
public:
    void Reset();

    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    char m_pad10[0x30 - 0x10];
    int m_30;
    char m_pad34[0x40 - 0x34];
    int m_40;
    int m_44;
    int m_48;
    char m_pad4c[0x54 - 0x4c];
    int m_54;
    char m_pad58[0x207c - 0x58];
    int m_207c;
};

void ResetState8cd490::Reset()
{
    m_0c = 0;
    m_04 = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_30 = 0;
    m_54 = 0;
    m_207c = 0;
}
