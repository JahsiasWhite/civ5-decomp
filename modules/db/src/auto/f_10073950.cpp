// c5d-cflags: -/EHsc
#include <string>

// src: GUESS 0x10073950 (confidence: high)
void __stdcall DestroyStringRange_10073950(std::string* first, std::string* last) {
    for (; first != last; ++first) {
        first->~basic_string();
    }
}
