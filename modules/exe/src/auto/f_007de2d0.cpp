// c5d-cflags: -/EHsc
#include <new>
#include <stddef.h>
#include <string>

// src: GUESS (confidence: low) [0x007de2d0]
struct StringPair7DE2D0 {
    std::string a;
    std::string b;
    // src: GUESS (confidence: low) [0x007de2d0]
    StringPair7DE2D0(const StringPair7DE2D0& o) : a(o.a), b(o.b) {}
};

// src: GUESS (confidence: low) [0x007de2d0]
void __cdecl fillStringPairs(StringPair7DE2D0* dst, size_t count, const StringPair7DE2D0& val) {
    while (count > 0) {
        if (dst) {
            new (dst) StringPair7DE2D0(val);
        }
        count--;
        dst++;
    }
}
