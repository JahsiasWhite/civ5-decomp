// c5d-cflags: -/arch:SSE2
// Copy constructor of a record of five floats and an int.

// src: GUESS (confidence: low)
struct Record_005f1e50
{
    // src: GUESS (confidence: low) [0x005f1e50]
    Record_005f1e50(const Record_005f1e50& other);

    float m_a;
    float m_b;
    float m_c;
    int m_d;
    float m_e;
    float m_f;
};

Record_005f1e50::Record_005f1e50(const Record_005f1e50& other)
    : m_a(other.m_a)
    , m_b(other.m_b)
    , m_c(other.m_c)
    , m_d(other.m_d)
    , m_e(other.m_e)
    , m_f(other.m_f)
{
}
