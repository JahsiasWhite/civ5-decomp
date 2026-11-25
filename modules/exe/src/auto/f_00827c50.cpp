// src: GUESS (confidence: low) [0x00827c50]
#include <algorithm>

struct KeyVal8 {
    unsigned int key;
    unsigned int val;
    bool operator<(const KeyVal8& rhs) const {
        return key < rhs.key;
    }
};

void __cdecl Med3KeyVal8(KeyVal8* first, KeyVal8* mid, KeyVal8* last) {
    if (*mid < *first) {
        std::iter_swap(mid, first);
    }
    if (*last < *mid) {
        std::iter_swap(last, mid);
    }
    if (*mid < *first) {
        std::iter_swap(mid, first);
    }
}
