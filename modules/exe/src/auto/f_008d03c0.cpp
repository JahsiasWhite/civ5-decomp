// src: GUESS (confidence: low)
class Buffer32_008d03c0 {
public:
    // src: GUESS 0x008d03c0 (confidence: high)
    void Fill(char ch);

    // src: GUESS (confidence: low)
    char m_buf[32];
};

void Buffer32_008d03c0::Fill(char ch) {
    for (unsigned int i = 0; i < 32; ++i) {
        if (ch == 0) {
            m_buf[i] = 0;
        } else if (i < 32) {
            m_buf[i] = ch;
        }
    }
}
