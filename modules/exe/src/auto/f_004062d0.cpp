#include <string>

// src: GUESS (confidence: high)
struct Unk_004062d0 {
    // src: GUESS (confidence: low)
    int m_pad[2];
    // src: GUESS (confidence: high)
    std::string m_str;

    // src: EXE [0x004062d0]
    const char* GetStr() const;
};

const char* Unk_004062d0::GetStr() const {
    return m_str.c_str();
}
