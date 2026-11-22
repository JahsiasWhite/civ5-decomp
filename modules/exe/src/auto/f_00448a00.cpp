#include <vector>

// src: GUESS (confidence: low) [0x00448a00]
class Class_00448a00 {
public:
    std::vector<void*> m_vec;

    // src: GUESS (confidence: low) [0x00448a00]
    void __thiscall Clear();
};

void __thiscall Class_00448a00::Clear() {
    m_vec.clear();
}
