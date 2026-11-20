// src: GUESS (confidence: low) [0x004690a0]
extern unsigned int GetLimit_004690a0();

// src: GUESS (confidence: low)
struct UnkObj_00590a30
{
    char m_pad[0x280];
    unsigned int m_val;

    void UpdateLimit_00590a30();
};

// src: GUESS (confidence: medium) [0x00590a30]
void UnkObj_00590a30::UpdateLimit_00590a30()
{
    m_val = (GetLimit_004690a0() > 8) ? 8 : GetLimit_004690a0();
}
