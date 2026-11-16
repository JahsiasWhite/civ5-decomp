// c5d-model: Gemini 3.8 Flash
#include <stdlib.h>

// src: GUESS (confidence: low)
class Unk_009563f0 {
public:
    unsigned __int64 m_val;
    // src: GUESS (confidence: high) [0x009563f0]
    unsigned __int64 Bswap64() const;
};

unsigned __int64 Unk_009563f0::Bswap64() const {
    return _byteswap_uint64(m_val);
}
