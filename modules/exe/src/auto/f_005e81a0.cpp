// c5d-model: Gemini 3.8 Flash
// c5d-cflags: /arch:SSE2
extern "C" extern const float g_float_009f72f4;

class Host_005e81a0 {
public:
    char pad[0x40];
    float m_f;
    int m_i;
    // src: GUESS (confidence: high) [0x005e81a0]
    Host_005e81a0();
};

Host_005e81a0::Host_005e81a0() {
    m_f = g_float_009f72f4;
    m_i = 0;
}
