// src: GUESS (confidence: low)
struct RleRun {
    unsigned short count;
    unsigned short val;
};

// src: GUESS (confidence: medium)
void __cdecl f_00515480(const RleRun* src, unsigned short count, unsigned short* dst) {
    int rem = count;
    do {
        for (int i = 0; i < (rem < src->count ? rem : src->count); ++i) {
            *dst++ = src->val;
        }
        rem -= src->count;
        ++src;
    } while (rem > 0);
}
