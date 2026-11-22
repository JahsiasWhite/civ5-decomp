typedef unsigned int uint32_t;
#include <string.h>

// src: GUESS (confidence: low) [0x007bad50]
struct Iter7BAD50 {
    int* p;
};

// src: GUESS (confidence: low) [0x007bad50]
struct F7BAD50 {
    uint32_t m_unk00;
    int*     m_begin;
    int*     m_end;

    // src: GUESS (confidence: low) [0x007bad50]
    Iter7BAD50 erase(Iter7BAD50 pos);
};

Iter7BAD50 F7BAD50::erase(Iter7BAD50 pos) {
    int* next = pos.p + 1;
    int count = (int)(m_end - next);
    if (count > 0) {
        memmove_s(pos.p, count * 4, next, count * 4);
    }
    m_end--;
    return pos;
}
