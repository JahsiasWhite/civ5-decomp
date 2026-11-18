// MD5 hasher constructor: not finalized, zero bit count, standard starting state.

// src: GUESS (confidence: medium)
class MD5_005bc120
{
public:
    // src: GUESS (confidence: medium) [0x005bc120]
    MD5_005bc120();

    // src: GUESS (confidence: medium)
    unsigned int m_state[4];
    // src: GUESS (confidence: medium)
    unsigned int m_count[2];
    // src: GUESS (confidence: medium)
    unsigned char m_buffer[64];
    // src: GUESS (confidence: medium)
    unsigned char m_digest[16];
    // src: GUESS (confidence: medium)
    bool m_finalized;
};

MD5_005bc120::MD5_005bc120()
{
    m_finalized = false;
    m_count[0] = 0;
    m_count[1] = 0;
    m_state[0] = 0x67452301;
    m_state[1] = 0xefcdab89;
    m_state[2] = 0x98badcfe;
    m_state[3] = 0x10325476;
}
