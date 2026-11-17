// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x008d03e0]
struct BufferHost_008d03e0 {
    char m_buf[0x20];
    void SetByte(char val, unsigned int idx);
};

// src: GUESS (confidence: high) [0x008d03e0]
void BufferHost_008d03e0::SetByte(char val, unsigned int idx)
{
    if (idx < 0x20)
        m_buf[idx] = val;
}
