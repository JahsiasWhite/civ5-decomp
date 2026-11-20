// src: GUESS (confidence: low) [0x00635da0]
struct Unk_00635da0
{
    unsigned short m_pad00;  // +0x00
    unsigned short m_flags;  // +0x02

    // src: GUESS (confidence: high) [0x00635da0]
    int IsType1Or2_00635da0();
};

// src: GUESS (confidence: high) [0x00635da0]
int Unk_00635da0::IsType1Or2_00635da0()
{
    if ((m_flags & 0xff) == 1 || (m_flags & 0xff) == 2)
        return 1;
    return 0;
}
