// c5d-cflags: -/arch:SSE2
#include <new>

// src: GUESS (confidence: low) [0x004e3df0]
struct Vec4_004e3df0 {
    float x, y, z, w;
    Vec4_004e3df0(const Vec4_004e3df0& o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

// src: GUESS (confidence: low) [0x004e3df0]
Vec4_004e3df0* __cdecl CopyRange_004e3df0(const Vec4_004e3df0* first, const Vec4_004e3df0* last, Vec4_004e3df0* dest) {
    for (; first != last; ++first, ++dest) {
        if (dest) {
            new (dest) Vec4_004e3df0(*first);
        }
    }
    return dest;
}
