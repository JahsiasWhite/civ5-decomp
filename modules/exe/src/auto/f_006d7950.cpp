// c5d-cflags: -/EHsc
#include <memory>

// src: GUESS (confidence: low)
struct UnkTarget_006d7950;

// src: GUESS (confidence: medium) [0x006d7950]
struct Host_006d7950 {
    int m_pad[0x82];
    // src: GUESS (confidence: medium)
    std::tr1::shared_ptr<UnkTarget_006d7950> m_first;
    // src: GUESS (confidence: medium)
    std::tr1::shared_ptr<UnkTarget_006d7950> m_second;

    // src: GUESS (confidence: medium) [0x006d7950]
    ~Host_006d7950();
};

// src: GUESS (confidence: medium) [0x006d7950]
Host_006d7950::~Host_006d7950() {
}
