// src: GUESS (confidence: low) [0x00672080]
struct UnkInfo_00672080
{
    char m_pad0[0x4b];
    // src: GUESS (confidence: low)
    bool m_flag;
};

// src: GUESS (confidence: low) [0x00672080]
class UnkOwner_00672080
{
public:
    // src: GUESS (confidence: low) [0x00672080]
    int IsFlagged();

    char m_pad0[0x5c];
    // src: GUESS (confidence: low)
    UnkInfo_00672080* m_info;
    char m_pad60[0x98 - 0x60];
    // src: GUESS (confidence: low)
    unsigned int m_bits;
};

int UnkOwner_00672080::IsFlagged()
{
    if (m_info->m_flag || ((unsigned char)(m_bits >> 8) & 1))
        return 1;
    return 0;
}
