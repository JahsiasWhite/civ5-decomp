#include <cstring>

// src: GUESS (confidence: low)
struct StrPair795 {
    char a[0x40];
    char b[0x200];
    int c;

    // src: GUESS (confidence: medium)
    StrPair795& operator=(const StrPair795& other);
};

StrPair795& StrPair795::operator=(const StrPair795& other) {
    c = other.c;
    strcpy_s(a, 0x40, other.a);
    strcpy_s(b, 0x200, other.b);
    return *this;
}
