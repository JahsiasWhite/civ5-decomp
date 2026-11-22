#include <cstring>

// src: GUESS (confidence: low)
struct NamedItem68 {
    char name[0x40];
    int id;
};

// src: GUESS (confidence: medium)
NamedItem68* __cdecl f_00852b50(const NamedItem68* begin, const NamedItem68* end, NamedItem68* dst) {
    for (; begin != end; ++begin, ++dst) {
        if (dst) {
            dst->id = begin->id;
            std::strcpy(dst->name, begin->name);
        }
    }
    return dst;
}
