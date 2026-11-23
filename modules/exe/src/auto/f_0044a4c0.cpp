// src: GUESS (confidence: high)
char* __stdcall fill_chars_n(char* dst, unsigned int count, const char* src) {
    unsigned int n = count;
    char* cur = dst;
    if (n > 0) {
        do {
            *cur = *src;
            --n;
            ++cur;
        } while (n > 0);
    }
    return dst + count;
}
