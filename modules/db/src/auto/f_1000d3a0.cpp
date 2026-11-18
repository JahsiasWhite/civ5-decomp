#include <memory>

// src: GUESS (confidence: low)
struct Elem_1000d3a0 {
    // src: GUESS (confidence: low)
    Elem_1000d3a0(const Elem_1000d3a0& other) : value(other.value) {}
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS 0x1000d3a0 (confidence: medium)
Elem_1000d3a0* __stdcall UninitCopyDwords_1000d3a0(const Elem_1000d3a0* first, const Elem_1000d3a0* last, Elem_1000d3a0* dest) {
    return std::uninitialized_copy(first, last, dest);
}
