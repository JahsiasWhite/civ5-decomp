// c5d-cflags: -/Ob1 +/Ob0
#include <string>

// src: GUESS (confidence: medium) [0x006c8f80]
class StringNullOrEmptyHelper {
public:
    std::string m_str;

    // src: GUESS (confidence: medium) [0x006c8f80]
    int __thiscall IsEmptyOrNull();
};

int __thiscall StringNullOrEmptyHelper::IsEmptyOrNull() {
    if (!m_str.empty() && m_str.c_str() != NULL) {
        return 0;
    }
    return 1;
}
