#include <vector>

// src: GUESS (confidence: low) [0x006440b0]
struct Entry92_006440b0 {
    char m_flag;
    char pad[0x5b];
};

// src: GUESS (confidence: low) [0x006440b0]
class Class_006440b0 {
public:
    char pad[0x60];
    std::vector<Entry92_006440b0> m_vec;

    // src: GUESS (confidence: low) [0x006440b0]
    void __thiscall ClearFlag(int idx);
};

void __thiscall Class_006440b0::ClearFlag(int idx) {
    if (idx >= 0 && idx < (int)m_vec.size()) {
        m_vec[idx].m_flag = 0;
    }
}
