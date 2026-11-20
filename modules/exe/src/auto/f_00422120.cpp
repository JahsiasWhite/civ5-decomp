// src: GUESS (confidence: low)
struct UnkSub_00422120
{
    int m_f00;             // +0x00
    unsigned short m_f04;  // +0x04

    // src: GUESS (confidence: high)
    UnkSub_00422120() : m_f00(0), m_f04(0) {}
};

// src: GUESS (confidence: low) [0x00422120]
class Unk_00422120
{
public:
    // src: GUESS (confidence: high) [0x00422120]
    Unk_00422120();
    // src: GUESS (confidence: low)
    virtual void Vfunc0();

private:
    UnkSub_00422120 m_sub04;  // +0x04
    int m_f0c;                // +0x0c
    int m_f10;                // +0x10
    int m_f14;                // +0x14
};

// src: GUESS (confidence: high) [0x00422120]
Unk_00422120::Unk_00422120()
{
    m_f10 = 0;
    m_f14 = 0;
    m_f0c = 0;
}
