// src: GUESS (confidence: medium) [0x10005510]
// c5d-cflags: -/EHsc -/D_HAS_EXCEPTIONS=0 +/D_HAS_EXCEPTIONS=1
#include <exception>
#include <string>

// src: GUESS (confidence: low)
class Unk_1008af64 : public std::exception {
public:
    // src: GUESS (confidence: medium) [0x10005510]
    virtual ~Unk_1008af64();

    // src: GUESS (confidence: low)
    std::string m_strMsg;  // +0x0c
};

Unk_1008af64::~Unk_1008af64() {
}
