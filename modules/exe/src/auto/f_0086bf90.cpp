// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: high) [0x009061c0]
struct FloatHost_009061c0 {
    char m_pad[0xb0];
    float m_val;
    char m_pad2[0xc0 - 0xb4];
    char m_flag;
    float GetValue() const;
};

// src: GUESS (confidence: high) [0x009061c0]
float FloatHost_009061c0::GetValue() const
{
    if (!m_flag)
        return 0.0f;
    return m_val;
}
