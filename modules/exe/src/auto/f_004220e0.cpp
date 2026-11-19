// src: GUESS (confidence: low)
struct PacketSink_007d9a50 {
    // src: GUESS (confidence: low)
    virtual void Send(void* data, unsigned int len);
};

// src: GUESS (confidence: low)
struct PacketBuffer_007d9a50 {
    char m_pad[0xfc50];
    // src: GUESS (confidence: medium)
    unsigned short m_len;
    char m_data[0xfbff];
    // src: GUESS (confidence: medium)
    PacketSink_007d9a50* m_pSink;
};

// src: GUESS (confidence: low) [0x007d9a50]
struct PacketWriter_007d9a50 {
    char* m_pCur;
    unsigned int m_cap;
    unsigned int m_rem;
    PacketBuffer_007d9a50* m_pBuf;

    // src: GUESS (confidence: medium) [0x007d9a50]
    void Flush();
};

// src: GUESS (confidence: medium) [0x007d9a50]
void PacketWriter_007d9a50::Flush() {
    m_pBuf->m_len = (unsigned short)(m_cap - m_rem);
    if (m_pBuf->m_pSink != 0) {
        m_pBuf->m_pSink->Send(&m_pBuf->m_len, m_pBuf->m_len + 2);
    }
}
