// src: GUESS (confidence: medium) [0x0052e4a0]
// src: GUESS (confidence: low)
struct PairShort_0052e4a0 {
    short m_a;
    short m_b;
};

// src: GUESS (confidence: low)
class Host_0052e4a0 {
public:
    char m_pad00[0xc8];
    PairShort_0052e4a0 m_items[10];  // +0xc8..+0xf0
    char m_padf0[0x14];
    unsigned char m_flag104;         // +0x104

    // src: GUESS (confidence: medium) [0x0052e4a0]
    Host_0052e4a0* Reset();
};

Host_0052e4a0* Host_0052e4a0::Reset() {
    m_items[0].m_a = 0; m_items[0].m_b = 0;
    m_items[1].m_a = 0; m_items[1].m_b = 0;
    m_items[2].m_a = 0; m_items[2].m_b = 0;
    m_items[3].m_a = 0; m_items[3].m_b = 0;
    m_items[4].m_a = 0; m_items[4].m_b = 0;
    m_items[5].m_a = 0; m_items[5].m_b = 0;
    m_items[6].m_a = 0; m_items[6].m_b = 0;
    m_items[7].m_a = 0; m_items[7].m_b = 0;
    m_items[8].m_a = 0; m_items[8].m_b = 0;
    m_items[9].m_a = 0; m_items[9].m_b = 0;
    m_flag104 = 0;
    return this;
}
