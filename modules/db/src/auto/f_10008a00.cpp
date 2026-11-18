// src: GUESS (confidence: low)
extern "C" unsigned char g_tolower_10078b60[256];

// src: GUESS 0x10008a00 (confidence: high)
bool CompareBytes_10008a00(const unsigned char* a, unsigned int lenA, const unsigned char* b, unsigned int lenB, bool caseSensitive) {
    if (lenA != lenB) {
        return false;
    }
    if (caseSensitive) {
        const unsigned char* end = a + lenA;
        for (; a < end; ++a, ++b) {
            if (*a != *b) {
                return false;
            }
        }
    } else {
        const unsigned char* end = a + lenA;
        for (; a < end; ++a, ++b) {
            if (g_tolower_10078b60[*a] != g_tolower_10078b60[*b]) {
                return false;
            }
        }
    }
    return true;
}
