#include <string.h>

// src: GUESS (confidence: low)
struct Keyed_100084f0 {
    // src: GUESS (confidence: low)
    virtual void GetKey(const char*& outPtr, unsigned int& outLen) = 0;
    // src: GUESS 0x100084f0 (confidence: medium)
    bool Matches(const char* other, const unsigned int& otherLen);
};

bool Keyed_100084f0::Matches(const char* other, const unsigned int& otherLen) {
    const char* ptr;
    unsigned int len;
    GetKey(ptr, len);
    if (len == otherLen) {
        if (strncmp(ptr, other, otherLen) == 0) {
            return true;
        }
    }
    return false;
}
