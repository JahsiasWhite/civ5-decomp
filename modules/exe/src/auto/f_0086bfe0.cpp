// c5d-model: Gemini 3.8 Flash
// c5d-cflags: -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: high) [0x00906210]
struct FloatHost_00906210 {
    char m_pad[0xb4];
    float m_val;
    char m_pad2[0xc0 - 0xb8];
    char m_flag;
    float GetValue() const;
};

// src: GUESS (confidence: high) [0x00906210]
float FloatHost_00906210::GetValue() const
{
    if (!m_flag)
        return 0.0f;
    return m_val;
}
