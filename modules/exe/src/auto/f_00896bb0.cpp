// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: high) [0x00896bb0]
struct Host_00896bb0 {
    char m_pad[0x31c];
    int m_val;
};

// src: GUESS (confidence: high) [0x00896bb0]
void GetField_00896bb0(const Host_00896bb0* host, int* out)
{
    *out = host->m_val;
}
