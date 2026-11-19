// c5d-model: Gemini 3.8 Flash
class Buffer_00717480 {
public:
    char* m_ptr;
    int m_size;
    int m_cap;
    char m_buf[0x40];
    // src: GUESS (confidence: high) [0x00717480]
    Buffer_00717480();
};

Buffer_00717480::Buffer_00717480() {
    m_size = 0;
    m_cap = 0x40;
    m_ptr = m_buf;
}
