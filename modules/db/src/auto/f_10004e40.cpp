#include <memory>

// src: GUESS (confidence: low)
struct Elem_10004e40 {
    // src: GUESS (confidence: low)
    Elem_10004e40(const Elem_10004e40& other) : value(other.value) {}
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS 0x10004e40 (confidence: medium)
Elem_10004e40* __stdcall UninitCopyDwords_10004e40(const Elem_10004e40* first, const Elem_10004e40* last, Elem_10004e40* dest) {
    return std::uninitialized_copy(first, last, dest);
}
