// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/arch:SSE2
class Host_00803ae0 {
public:
    char pad[0x70];
    unsigned int m_count;
    // src: GUESS (confidence: high) [0x00803ae0]
    float __thiscall GetScaled() const;
};

float Host_00803ae0::GetScaled() const {
    return (float)m_count * 222.0f;
}
