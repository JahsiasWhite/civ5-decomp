// c5d-cflags: -/EHsc
#include <string>

// src: GUESS (confidence: low)
class Wrapper_10071e70 {
public:
    // src: GUESS 0x10071e70 (confidence: medium)
    void* ScalarDeletingDtor(unsigned int flags);

private:
    // src: GUESS (confidence: low)
    std::string m_str;
};

void* Wrapper_10071e70::ScalarDeletingDtor(unsigned int flags) {
    m_str.~basic_string();
    if (flags & 1) {
        ::operator delete(this);
    }
    return this;
}
