#include <stdlib.h>

// src: GUESS (confidence: high) [0x004d49a0]
struct HashBucket_004d49a0 {
    int m_pad0[8];
    // src: GUESS (confidence: high)
    unsigned int m_mask;
    // src: GUESS (confidence: high)
    unsigned int m_count;

    // src: GUESS (confidence: medium) [0x004d49a0]
    unsigned int CalcBucket(const unsigned int* key) const;
};

// src: GUESS (confidence: medium) [0x004d49a0]
unsigned int HashBucket_004d49a0::CalcBucket(const unsigned int* key) const {
    ldiv_t qr = ldiv((*key ^ 0xdeadbeef) & 0x7fffffff, 0x1f31d);
    long v = qr.rem * 0x41a7 - qr.quot * 0xb14;
    if (v < 0) {
        v += 0x7fffffff;
    }
    unsigned int idx = (unsigned int)v & m_mask;
    if (m_count <= idx) {
        idx += (~0u - (m_mask >> 1));
    }
    return idx;
}
