// c5d-cflags: +/Od -/arch:SSE2
// Stores three floats into the object, in reverse field order.

// src: GUESS (confidence: low)
struct Target_00896c30
{
    char m_pad0[0x338];
    // src: GUESS (confidence: low)
    float m_c;
    // src: GUESS (confidence: low)
    float m_b;
    // src: GUESS (confidence: low)
    float m_a;
};

// src: GUESS (confidence: low) [0x00896c30]
void SetValues_00896c30(Target_00896c30* target, float a, float b, float c)
{
    target->m_a = a;
    target->m_b = b;
    target->m_c = c;
}
