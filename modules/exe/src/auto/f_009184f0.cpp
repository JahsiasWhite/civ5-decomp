// Sets the value, clamped to [0, g_float_009f72f4], and clears the field at
// 0xc.

extern "C" float g_float_009f72f4;

// src: GUESS (confidence: low)
class Clamped_009184f0
{
public:
    // src: GUESS (confidence: low) [0x009184f0]
    void SetValue(float value);

    // src: GUESS (confidence: low)
    float m_value;
    int m_04;
    int m_08;
    // src: GUESS (confidence: low)
    int m_0c;
};

void Clamped_009184f0::SetValue(float value)
{
    float clamped;
    if (0.0f > value)
        clamped = 0.0f;
    else if (value > g_float_009f72f4)
        clamped = g_float_009f72f4;
    else
        clamped = value;
    m_value = clamped;
    m_0c = 0;
}
