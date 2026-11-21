// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x007aab80]
struct Unknown7aab80 {
    int m_0;
    unsigned int m_4;
};

// src: GUESS (confidence: high) [0x007aab80]
extern "C" void __cdecl f_007aab80(Unknown7aab80* out, float val) {
    out->m_4 = (unsigned int)val;
}
