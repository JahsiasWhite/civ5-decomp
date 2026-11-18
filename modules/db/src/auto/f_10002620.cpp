// c5d-cflags: -/EHsc
#include <string>

// src: GUESS (confidence: low)
class Wrapper_10002620 {
public:
    // src: GUESS 0x10002620 (confidence: medium)
    void* ScalarDeletingDtor(unsigned int flags);

private:
    int m_pad00[2];
    // src: GUESS (confidence: low)
    std::string m_str;
};

void* Wrapper_10002620::ScalarDeletingDtor(unsigned int flags) {
    m_str.~basic_string();
    if (flags & 1) {
        ::operator delete(this);
    }
    return this;
}
