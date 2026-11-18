// src: GUESS (confidence: low)
struct PacketBuffer_007d9a10 {
    char m_pad[0xfc52];
    // src: GUESS (confidence: medium)
    unsigned short m_header;
};

// src: GUESS (confidence: low) [0x007d9a10]
struct PacketWriter_007d9a10 {
    char* m_pCur;
    unsigned int m_cap;
    unsigned int m_rem;
    PacketBuffer_007d9a10* m_pBuf;

    // src: GUESS (confidence: medium) [0x007d9a10]
    PacketWriter_007d9a10(PacketBuffer_007d9a10* buf, unsigned short header);
};

// src: GUESS (confidence: medium) [0x007d9a10]
PacketWriter_007d9a10::PacketWriter_007d9a10(PacketBuffer_007d9a10* buf, unsigned short header)
    : m_pCur((char*)&buf->m_header)
    , m_cap(0xfbff)
    , m_rem(0xfbff)
    , m_pBuf(buf)
{
    *m_pCur;
    buf->m_header = header;
    m_rem -= 2;
    m_pCur += 2;
}
