#include <memory>

// src: GUESS (confidence: low)
struct Elem_10004e10 {
    // src: GUESS (confidence: low)
    Elem_10004e10(const Elem_10004e10& other) : value(other.value) {}
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS 0x10004e10 (confidence: medium)
Elem_10004e10* __stdcall UninitCopyDwords_10004e10(const Elem_10004e10* first, const Elem_10004e10* last, Elem_10004e10* dest) {
    return std::uninitialized_copy(first, last, dest);
}
