// src: GUESS (confidence: medium) [0x007062d0]
#include <cstring>
#include <memory>

// src: GUESS (confidence: low)
class Host_007062d0 {
public:
    char m_data[0x208];                      // +0x000..+0x207
    std::tr1::shared_ptr<void> m_sp208;      // +0x208..+0x20f
    std::tr1::shared_ptr<void> m_sp210;      // +0x210..+0x217

    // src: GUESS (confidence: medium) [0x007062d0]
    void Reset();
};

void Host_007062d0::Reset() {
    m_sp210.reset();
    m_sp208.reset();
    std::memset(m_data, 0, sizeof(m_data));
}
