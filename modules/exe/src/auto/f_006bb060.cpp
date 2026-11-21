// c5d-cflags: -/arch:SSE2
#include <new>

// src: GUESS (confidence: low)
struct UnkStruct24_006bb060
{
    float m_a;
    float m_b;
    float m_c;
    int m_d;
    float m_e;
    float m_f;

    UnkStruct24_006bb060(const UnkStruct24_006bb060& o)
        : m_a(o.m_a), m_b(o.m_b), m_c(o.m_c), m_d(o.m_d), m_e(o.m_e), m_f(o.m_f)
    {
    }
};

// src: LIB [0x006bb060]
UnkStruct24_006bb060* CopyRange24_006bb060(const UnkStruct24_006bb060* first, const UnkStruct24_006bb060* last, UnkStruct24_006bb060* dst)
{
    for (; first != last; ++first, ++dst)
        new ((void*)dst) UnkStruct24_006bb060(*first);
    return dst;
}
