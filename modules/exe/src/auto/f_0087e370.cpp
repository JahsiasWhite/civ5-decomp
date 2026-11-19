// Constructs the record with its three scale values at the default
// (g_float_009f72f4), the rest cleared.

extern "C" float g_float_009f72f4;

// src: GUESS (confidence: low)
struct Record_00918520
{
    // src: GUESS (confidence: low) [0x00918520]
    Record_00918520();

    // src: GUESS (confidence: low)
    float m_a;
    // src: GUESS (confidence: low)
    float m_b;
    // src: GUESS (confidence: low)
    float m_c;
    // src: GUESS (confidence: low)
    int m_d;
    // src: GUESS (confidence: low)
    float m_e;
    // src: GUESS (confidence: low)
    int m_f;
    // src: GUESS (confidence: low)
    bool m_g;
};

Record_00918520::Record_00918520()
{
    m_a = g_float_009f72f4;
    m_e = g_float_009f72f4;
    m_b = g_float_009f72f4;
    m_f = 0;
    m_g = false;
    m_c = 0.0f;
    m_d = 0;
}
