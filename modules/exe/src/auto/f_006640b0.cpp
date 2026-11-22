#include <cstring>

// src: GUESS (confidence: low)
struct Vec3 {
    int x, y, z;
};

// src: GUESS (confidence: low)
struct Mat44 {
    int m[16];
};

// src: GUESS (confidence: medium)
Mat44* __cdecl f_006640b0(Mat44* dst, const Vec3* src) {
    std::memset(dst, 0, sizeof(Mat44));
    dst->m[15] = 1;
    dst->m[10] = 1;
    dst->m[5] = 1;
    dst->m[0] = 1;
    dst->m[12] = src->x;
    dst->m[13] = src->y;
    dst->m[14] = src->z;
    return dst;
}
