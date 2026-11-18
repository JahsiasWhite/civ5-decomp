// src: GUESS (confidence: medium) [0x008e4bc0]
// c5d-cflags: -/arch:SSE2 +/Oi
#include <cmath>

// src: GUESS (confidence: low)
class Host_008e4bc0 {
public:
    char m_pad00[0xc0];
    // src: GUESS (confidence: medium)
    float m_fMinX;   // +0xc0
    float m_fMaxX;   // +0xc4
    float m_fMinY;   // +0xc8
    float m_fMaxY;   // +0xcc

    // src: GUESS (confidence: medium) [0x008e4bc0]
    double CalcSpanDeg() const;
};

double Host_008e4bc0::CalcSpanDeg() const {
    float dx = m_fMaxX - m_fMinX;
    float dy = m_fMaxY - m_fMinY;
    float halfDist = std::sqrt(dx * dx + dy * dy) * 0.5f;
    float fTwoAngle = std::atan(halfDist) * 2.0f;
    return fTwoAngle * 57.29577951308232;
}
