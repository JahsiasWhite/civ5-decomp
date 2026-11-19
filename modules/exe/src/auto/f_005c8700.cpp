// src: GUESS (confidence: medium) [0x0063cf10]
// c5d-cflags: -/arch:SSE2 +/Oi
#include <cstring>

// src: GUESS (confidence: low)
class Struct_0063cf10 {
public:
    int m_i00;
    int m_i04;
    float m_f08;
    float m_f0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    unsigned char m_b28;
    int m_i2c;
    int m_arr30[0x110];
    float m_f470;
    float m_f474;
    int m_i478;
    int m_arr47c[0xb];

    // src: GUESS (confidence: medium) [0x0063cf10]
    Struct_0063cf10& operator=(const Struct_0063cf10& rhs);
};

Struct_0063cf10& Struct_0063cf10::operator=(const Struct_0063cf10& rhs) {
    m_i00 = rhs.m_i00;
    m_i04 = rhs.m_i04;
    m_f08 = rhs.m_f08;
    m_f0c = rhs.m_f0c;
    m_i10 = rhs.m_i10;
    m_i14 = rhs.m_i14;
    m_i18 = rhs.m_i18;
    m_i1c = rhs.m_i1c;
    m_i20 = rhs.m_i20;
    m_i24 = rhs.m_i24;
    m_b28 = rhs.m_b28;
    m_i2c = rhs.m_i2c;
    std::memcpy(m_arr30, rhs.m_arr30, sizeof(m_arr30));
    m_f470 = rhs.m_f470;
    m_f474 = rhs.m_f474;
    m_i478 = rhs.m_i478;
    std::memcpy(m_arr47c, rhs.m_arr47c, sizeof(m_arr47c));
    return *this;
}
