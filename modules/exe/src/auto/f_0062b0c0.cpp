// c5d-cflags: -/EHsc
#include <memory>
#include <string.h>

// src: GUESS (confidence: low)
struct UnkTarget_0062b0c0;

// src: GUESS (confidence: medium) [0x0062b0c0]
struct ZeroStruct_0062b0c0 {
    int m_pad[0x82];
    // src: GUESS (confidence: medium)
    std::tr1::shared_ptr<UnkTarget_0062b0c0> m_first;
    // src: GUESS (confidence: medium)
    std::tr1::shared_ptr<UnkTarget_0062b0c0> m_second;

    // src: GUESS (confidence: medium) [0x0062b0c0]
    ZeroStruct_0062b0c0();
};

// src: GUESS (confidence: medium) [0x0062b0c0]
ZeroStruct_0062b0c0::ZeroStruct_0062b0c0() {
    memset(this, 0, 0x208);
}
