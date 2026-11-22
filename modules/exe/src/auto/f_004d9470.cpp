// src: GUESS (confidence: low)
struct Item64 {
    int data[16];
};

// src: GUESS (confidence: medium)
Item64* __stdcall f_004d9470(Item64* dst, unsigned int count, const Item64* src) {
    Item64* p = dst;
    unsigned int n = count;
    if (n > 0) {
        do {
            if (p) {
                *p = *src;
            }
            --n;
            ++p;
        } while (n > 0);
    }
    return dst + count;
}
