// SHA-1 hasher constructor: the standard starting state, a zero bit count
// and the block cursor at the start of the buffer.

// src: GUESS (confidence: medium)
class SHA1_00925cf0
{
public:
    // src: GUESS (confidence: medium) [0x00925cf0]
    SHA1_00925cf0();

    // src: GUESS (confidence: medium)
    unsigned int m_state[5];
    // src: GUESS (confidence: medium)
    unsigned int m_count[2];
    char m_pad1c[0x70 - 0x1c];
    // src: GUESS (confidence: medium)
    unsigned char m_buffer[64];
    // src: GUESS (confidence: medium)
    unsigned char* m_cursor;
};

SHA1_00925cf0::SHA1_00925cf0()
{
    m_cursor = m_buffer;
    m_state[0] = 0x67452301;
    m_state[1] = 0xefcdab89;
    m_state[2] = 0x98badcfe;
    m_state[3] = 0x10325476;
    m_state[4] = 0xc3d2e1f0;
    m_count[0] = 0;
    m_count[1] = 0;
}
