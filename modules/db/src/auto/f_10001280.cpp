// c5d-cflags: -/EHsc
#include <exception>
#include <string>

// src: GUESS (confidence: low)
class Unk_10001280 : public stdext::exception {
public:
    // src: GUESS 0x10001280 (confidence: medium)
    virtual ~Unk_10001280();

private:
    // src: GUESS (confidence: medium)
    std::string m_message;
};

Unk_10001280::~Unk_10001280() {
}
