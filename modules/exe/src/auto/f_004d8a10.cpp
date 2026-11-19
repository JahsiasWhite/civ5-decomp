// c5d-cflags: -/arch:SSE2
// Copy constructor of a record of three ints, three floats and a flag.

// src: GUESS (confidence: low)
struct Record_006ae750
{
    // src: GUESS (confidence: low) [0x006ae750]
    Record_006ae750(const Record_006ae750& other);

    int m_a;
    int m_b;
    int m_c;
    float m_x;
    float m_y;
    float m_z;
    bool m_flag;
};

Record_006ae750::Record_006ae750(const Record_006ae750& other)
    : m_a(other.m_a)
    , m_b(other.m_b)
    , m_c(other.m_c)
    , m_x(other.m_x)
    , m_y(other.m_y)
    , m_z(other.m_z)
    , m_flag(other.m_flag)
{
}
