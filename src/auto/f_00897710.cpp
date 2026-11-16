// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: high) [0x00897710]
struct Host_00897710 {
    char m_pad[0xe8];
    int m_val;
};

// src: GUESS (confidence: high) [0x00897710]
int GetByteField_00897710(const Host_00897710* host)
{
    return host->m_val & 0xff;
}
