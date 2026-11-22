#include <cstring>

// src: GUESS (confidence: low)
class StreamReader664 {
public:
    char pad[0x10264];
    const char* end;
    const char* cur;

    // src: GUESS (confidence: medium)
    bool ReadInts(int* out, unsigned int count);
};

bool StreamReader664::ReadInts(int* out, unsigned int count) {
    unsigned int bytes = count * 4;
    bool ok = false;
    if (cur + bytes <= end) {
        std::memcpy(out, cur, bytes);
        ok = true;
    }
    cur += bytes;
    return ok;
}
