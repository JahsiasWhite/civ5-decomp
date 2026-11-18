// c5d-cflags: -/EHsc
#include <string>

// src: GUESS 0x100721a0 (confidence: high)
void FillStringRange_100721a0(std::string* first, std::string* last, const std::string& val) {
    for (; first != last; ++first) {
        *first = val;
    }
}
