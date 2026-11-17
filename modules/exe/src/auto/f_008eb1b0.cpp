// c5d-model: Gemini 4 Hydrogen
#include <vector>

// src: GUESS (confidence: high)
struct Inner_008eb1b0 {
    char m_pad[0x70];
    std::vector<int> m_vec;
};

// src: GUESS (confidence: high)
class Host_008eb1b0 {
public:
    int* GetFirstOrNull();
    int m_pad0;
    Inner_008eb1b0* m_inner;
};

// src: GUESS (confidence: high) [0x008eb1b0]
int* Host_008eb1b0::GetFirstOrNull() {
    if (m_inner && m_inner->m_vec.size() > 0) {
        return &m_inner->m_vec[0];
    }
    return 0;
}
