// c5d-model: claude-opus-5-5
// Constructor of a small record: leaves the first word alone and zeroes the
// five words after it (the +0x14 word is cleared before +0x10).

class ZeroedRecord_007901d0
{
public:
    ZeroedRecord_007901d0();

private:
    int m_first;
    int m_a;
    int m_b;
    int m_c;
    int m_d;
    int m_e;
};

ZeroedRecord_007901d0::ZeroedRecord_007901d0()
{
    m_a = 0;
    m_b = 0;
    m_c = 0;
    m_e = 0;
    m_d = 0;
}
